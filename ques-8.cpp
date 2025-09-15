#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool isDistinct = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct) count++;
    }
    return count;
}

int main() {
    int arr[] = {4, 2, 4, 5, 2, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Total distinct elements: " << countDistinct(arr, n) << endl;
    return 0;
}
