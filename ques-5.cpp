a)
A[i][j] = 0   if i ≠ j
store[i] = A[i][i]
code:
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of Diagonal Matrix: ";
    cin >> n;

    int diag[n];
    cout << "Enter diagonal elements:\n";
    for (int i = 0; i < n; i++) cin >> diag[i];

    cout << "Diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << diag[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}
b)
#include <iostream>
using namespace std;

class TriDiagonal {
    int *A, n;
public:
    TriDiagonal(int n) {
        this->n = n;
        A = new int[3*n - 2];
    }
    void set(int i, int j, int x) {
        if (i - j == 1) A[i-2] = x;             
        else if (i - j == 0) A[n-1 + i-1] = x;  
        else if (i - j == -1) A[2*n-1 + i-1] = x; 
    }
    int get(int i, int j) {
        if (i - j == 1) return A[i-2];
        else if (i - j == 0) return A[n-1 + i-1];
        else if (i - j == -1) return A[2*n-1 + i-1];
        else return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter dimension of Tri-diagonal Matrix: ";
    cin >> n;

    TriDiagonal td(n);

    cout << "Enter elements row-wise:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            td.set(i,j,x);
        }
    }

    cout << "Tri-diagonal Matrix:\n";
    td.display();

    return 0;
}
c)
#include <iostream>
using namespace std;

class LowerTriangular {
    int *A, n;
public:
    LowerTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j) A[i*(i-1)/2 + (j-1)] = x;
    }
    int get(int i, int j) {
        if (i >= j) return A[i*(i-1)/2 + (j-1)];
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter dimension of Lower Triangular Matrix: ";
    cin >> n;

    LowerTriangular lt(n);

    cout << "Enter elements row-wise:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            lt.set(i,j,x);
        }
    }

    cout << "Lower Triangular Matrix:\n";
    lt.display();

    return 0;
}
d)
#include <iostream>
using namespace std;

class UpperTriangular {
    int *A, n;
public:
    UpperTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i <= j) A[(i-1)*n - ((i-1)*(i-2))/2 + (j-i)] = x;
    }
    int get(int i, int j) {
        if (i <= j) return A[(i-1)*n - ((i-1)*(i-2))/2 + (j-i)];
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter dimension of Upper Triangular Matrix: ";
    cin >> n;

    UpperTriangular ut(n);

    cout << "Enter elements row-wise:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            ut.set(i,j,x);
        }
    }

    cout << "Upper Triangular Matrix:\n";
    ut.display();

    return 0;
}
e)
#include <iostream>
using namespace std;

class SymmetricMatrix {
    int *A, n;
public:
    SymmetricMatrix(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j) A[i*(i-1)/2 + (j-1)] = x;
    }
    int get(int i, int j) {
        if (i >= j) return A[i*(i-1)/2 + (j-1)];
        else return A[j*(j-1)/2 + (i-1)];
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter dimension of Symmetric Matrix: ";
    cin >> n;

    SymmetricMatrix sm(n);

    cout << "Enter elements of lower triangle:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int x; cin >> x;
            sm.set(i,j,x);
        }
    }

    cout << "Symmetric Matrix:\n";
    sm.display();

    return 0;
}
