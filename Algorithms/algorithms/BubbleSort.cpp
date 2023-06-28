#include "iostream"
using namespace std;

// Bubble Sort in C++
void bubbleSort(int array[], int size) {

    // run loops two times: one for walking through the array
    // and the other for comparison
    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {

            // If element at current index is greater than next element, swap the two.
            // To sort in descending order, change > to < in this line.
            if (array[i] > array[i + 1]) {

                // Swap arr[j] and arr[j + 1]
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << " " << array[i];
    }
    cout << endl;
}

// Driver code
int main() {
    int array[] = {9, 5, 1, 4, 2};
    int size = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, size);
    cout << "Sorted array in ascending order: ";
    printArray(array, size);
}

// The time complexity of the above implementation of bubble sort is O(n^2).
// Best case time complexity: O(n)
// Worst case time complexity: O(n^2)
// Average case time complexity: O(n^2)
