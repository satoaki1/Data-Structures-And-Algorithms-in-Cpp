#include "iostream"
using namespace std;

// Counting Sort in C++

// Function to sort array using counting sort
void countingSort(int array[], int size) {
    int output[10];
    int count[10];
    int max = array[0];

    // Find the largest element of the array
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // Initialize count array with all zeros.
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << "  ";
    }
    cout << endl;
}

// Driver code
int main() {
    int array[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(array) / sizeof(array[0]);
    countingSort(array, n);
    cout << "Sorted array in ascending order: ";
    printArray(array, n);
}

// The time complexity of the above algorithm is O(n+k), where n is the size of the input array and k is the range of the input.
// Best case time complexity: O(n+k)
// Worst case time complexity: O(n+k)
// Average case time complexity: O(n+k)