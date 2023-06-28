#include "iostream"
using namespace std;

// Insertion Sort in C++
void insertionSort(int array[], int size) {

    // run the loop from the second element
    // because the first element is already sorted
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

// Function to print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << " " << array[i];
    }
    cout << endl;
}

// Driver code
int main() {
    int data[] = {9, 5, 1, 4, 3};
    int size = sizeof(data) / sizeof(data[0]);
    insertionSort(data, size);
    cout << "Sorted array in ascending order: ";
    printArray(data, size);
}

// The time complexity of the above implementation of insertion sort is O(n^2).
// Best case time complexity: O(n)
// Worst case time complexity: O(n^2)
// Average case time complexity: O(n^2)