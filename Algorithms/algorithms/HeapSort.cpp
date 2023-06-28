#include "iostream"
using namespace std;

// Heap Sort in C++

// Function to swap the position of two elements
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Function to heapify the tree
void heapify(int array[], int size, int i) {
    if (size == 1) {
        cout << "Single element in the heap" << endl;
    } else {
        // Find the largest among root, left child and right child
        int largest = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < size && array[leftChild] > array[largest])
            largest = leftChild;

        if (rightChild < size && array[rightChild] > array[largest])
            largest = rightChild;

        // Swap and continue heapifying if root is not largest
        if (largest != i) {
            swap(array[i], array[largest]);
            heapify(array, size, largest);
        }
    }
}

// Function to build a heap
void heapSort(int array[], int size) {
    // Heapify from the lowest non-leaf node
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);
    for (int i = size - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i)
        cout << array[i] << " ";
    cout << endl;
}

// Main code
int main() {
    int arr[] = {1, 4, 3, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, size);
    cout << "Sorted array in ascending order: ";
    printArray(arr, size);
}

// The time complexity of the above implementation of heap sort is O(n*log n).
// Best case time complexity: O(n*log n)
// Worst case time complexity: O(n*log n)
// Average case time complexity: O(n*log n)