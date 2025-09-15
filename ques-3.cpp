a)
#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return n; // if last number is missing
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; 
    int n = 6;

    cout << "Missing number (Linear): " << findMissingLinear(arr, n) << endl;
    return 0;
}
b)
#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 2;  // array size = n-1
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == mid + 1) {
            low = mid + 1;  // search right
        } else {
            high = mid - 1; // search left
        }
    }
    return low + 1; // missing number
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; 
    int n = 6;

    cout << "Missing number (Binary Search): " << findMissingBinary(arr, n) << endl;
    return 0;
}
