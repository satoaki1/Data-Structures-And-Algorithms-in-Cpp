#include "iostream"
using namespace std;

// Quick Sort in C++

// Function to swap position of elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* This function takes last element as pivot, places
 * the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right
 * of pivot */
int partition(int array[], int low, int high) {

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) { // if element smaller than pivot is found
            i++; // swap it with the greater element pointed by i
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]); // swap pivot with greater element
    return (i + 1);
}

// function to implement quick sort
void quickSort(int array[], int low, int high) {
    if (low < high) {

        // Select pivot position and put all the elements smaller
        // than pivot on left and greater than pivot on right
        int pi = partition(array, low, high);

        // sort the elements on the left of the pivot
        quickSort(array, low, pi - 1);

        // sort the elements on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

// function to print array elements
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << " " << array[i];
    }
    cout << endl;
}

// driver code
int main() {
    int data[] = {8, 7, 2, 1, 0, 9, 6};
    int n = sizeof(data) / sizeof(data[0]);
    quickSort(data, 0, n - 1);
    cout << "Sorted array in ascending order: ";
    printArray(data, n);
}

// The time complexity of the above implementation of quick sort is O(n^2).
// Best case time complexity: O(n*log n)
// Worst case time complexity: O(n^2)
// Average case time complexity: O(n*log n)