#include <iostream>
using namespace std;

#define MAX 100

// Function to convert normal matrix to triplet form
void convertToTriplet(int mat[10][10], int m, int n, int triplet[MAX][3]) {
    int k = 1; // index for triplet (0 reserved for metadata)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = mat[i][j];
                k++;
            }
        }
    }
    triplet[0][0] = m;
    triplet[0][1] = n;
    triplet[0][2] = k-1; // number of non-zero elements
}

// Display triplet
void displayTriplet(int triplet[MAX][3]) {
    int t = triplet[0][2];
    cout << "Row Col Val\n";
    for (int i = 0; i <= t; i++) {
        cout << triplet[i][0] << "   " 
             << triplet[i][1] << "   " 
             << triplet[i][2] << endl;
    }
}

// (a) Transpose
void transpose(int triplet[MAX][3], int trans[MAX][3]) {
    int t = triplet[0][2];
    trans[0][0] = triplet[0][1];
    trans[0][1] = triplet[0][0];
    trans[0][2] = t;

    int k = 1;
    for (int col = 0; col < triplet[0][1]; col++) {
        for (int i = 1; i <= t; i++) {
            if (triplet[i][1] == col) {
                trans[k][0] = triplet[i][1];
                trans[k][1] = triplet[i][0];
                trans[k][2] = triplet[i][2];
                k++;
            }
        }
    }
}

// (b) Addition
void add(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Matrix dimensions mismatch!\n";
        return;
    }

    int i=1, j=1, k=1;
    int t1 = A[0][2], t2 = B[0][2];
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i<=t1 && j<=t2) {
        if (A[i][0] < B[j][0] || 
           (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0] || 
                (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else { // same position
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }
    while (i <= t1) { C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2]; i++; k++; }
    while (j <= t2) { C[k][0]=B[j][0]; C[k][1]=B[j][1]; C[k][2]=B[j][2]; j++; k++; }

    C[0][2] = k-1;
}

// (c) Multiplication
void multiply(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Matrix dimensions mismatch for multiplication!\n";
        return;
    }

    int m = A[0][0], n = B[0][1];
    int temp[10][10] = {0};

    for (int i=1; i<=A[0][2]; i++) {
        for (int j=1; j<=B[0][2]; j++) {
            if (A[i][1] == B[j][0]) {
                temp[A[i][0]][B[j][1]] += A[i][2] * B[j][2];
            }
        }
    }

    // Convert result to triplet
    convertToTriplet(temp, m, n, C);
}

int main() {
    int A[10][10] = {{0,0,3,0,4},{0,0,5,7,0},{0,0,0,0,0},{0,2,6,0,0}};
    int B[10][10] = {{1,0,0,0,0},{0,0,0,0,0},{0,0,2,0,0},{0,0,0,0,3},{0,0,0,0,0}};

    int TA[MAX][3], TB[MAX][3], C[MAX][3], D[MAX][3];
    int tripletA[MAX][3], tripletB[MAX][3];

    convertToTriplet(A,4,5,tripletA);
    convertToTriplet(B,5,5,tripletB);

    cout << "Matrix A (triplet):\n"; displayTriplet(tripletA);
    cout << "\nMatrix B (triplet):\n"; displayTriplet(tripletB);

    transpose(tripletA, TA);
    cout << "\nTranspose of A:\n"; displayTriplet(TA);

    add(tripletA, tripletA, C);
    cout << "\nA + A:\n"; displayTriplet(C);

    multiply(tripletA, tripletB, D);
    cout << "\nA * B:\n"; displayTriplet(D);

    return 0;
}
