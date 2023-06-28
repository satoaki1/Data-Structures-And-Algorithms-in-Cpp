#include "iostream"
using namespace std;

// Linear Search in C++

// Function to search x in arr[]
int linearSearch(int arr[], int n, int x) {
    // Going through array sequentially
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

// Driver code
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int x = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = linearSearch(arr, n, x);
    (result == -1) ? cout << "Element is not present in array" << endl
                   : cout << "Element is present at index " << result << endl;
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)