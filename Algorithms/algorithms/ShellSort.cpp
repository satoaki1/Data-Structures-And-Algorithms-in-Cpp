#include "iostream"
using namespace std;

// Shell Sort in C++

// Function to sort array using shellSort
int shellSort(int array[], int n) {
    // Rearrange elements at each n/2, n/4, n/8, ... intervals
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
    return 0;
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << " " << array[i];
    }
    cout << endl;
}

// Driver code
int main() {
    int data[] = {9, 8, 3, 7, 5, 6, 4, 1};
    int size = sizeof(data) / sizeof(data[0]);
    shellSort(data, size);
    cout << "Sorted array in ascending order: ";
    printArray(data, size);
}

// The time complexity of the above implementation of shell sort is O(n2).
// Best case time complexity: O(n*log n)
// Worst case time complexity: O(n2)
// Average case time complexity: O(n*log n)