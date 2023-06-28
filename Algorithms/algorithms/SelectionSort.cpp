#include "iostream"
using namespace std;

// Selection Sort in C++

// function to swap the position of two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// function to perform selection sort
void selectionSort(int array[], int size) {

    // run (size - 1) times
    // because last element will automatically be sorted
    for (int i = 0; i < size - 1; i++) {

        // find the minimum element in the unsorted subarray[i..size-1]
        int min_idx = i;

        // loop through the unsorted subarray
        for (int j = i + 1; j < size; j++) {

            // if the element is less, then it is the new minimum
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        // swap the minimum element with the first element in the unsorted subarray[i..size-1]
        swap(&array[min_idx], &array[i]);
    }
}

// function to print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << " " << array[i];
    }
    cout << endl;
}

// driver code
int main() {
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);
    selectionSort(data, size);
    cout << "Sorted array in ascending Order: ";
    printArray(data, size);
}

// The time complexity of the above implementation of selection sort is O(n^2).
// Best case time complexity: O(n^2)
// Worst case time complexity: O(n^2)
// Average case time complexity: O(n^2)