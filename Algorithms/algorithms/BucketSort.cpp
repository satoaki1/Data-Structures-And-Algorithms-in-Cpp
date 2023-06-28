#include <iomanip>
#include <iostream>
using namespace std;

// Bucket sort in C++

#define NARRAY 7   // Array size
#define NBUCKET 6  // Number of buckets
#define INTERVAL 10  // Each bucket capacity

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to perform bucket sort
struct Node *insertionSort(struct Node *list) {
    struct Node *k, *nodeList;
    if (list == 0 || list->next == 0) {
        return list;
    }
    nodeList = list;
    k = list->next;
    nodeList->next = 0;
    while (k != 0) {
        struct Node *ptr;
        if (nodeList->data > k->data) {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = nodeList;
            nodeList = tmp;
            continue;
        }
        for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
            if (ptr->next->data > k->data)
                break;
        }
        if (ptr->next != 0) {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        } else {
            ptr->next = k;
            k = k->next;
            ptr->next->next = 0;
            continue;
        }
    }
    return nodeList;
}

void printBuckets(Node *pNode);

// Function to sort the elements of each bucket
void bucketSort(int array[]) {
    int i, j;
    struct Node **buckets;

    // Create buckets and allocate memory size
    buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);

    // Initialize empty buckets
    for (i = 0; i < NBUCKET; ++i) {
        buckets[i] = NULL;
    }

    // Fill the buckets with respective elements
    for (i = 0; i < NARRAY; ++i) {
        struct Node *current;
        int pos = (int)array[i] / INTERVAL;
        current = (struct Node *)malloc(sizeof(struct Node));
        current->data = array[i];
        current->next = buckets[pos];
        buckets[pos] = current;
    }

    // Sort the elements of each bucket
    for (i = 0; i < NBUCKET; ++i) {
        buckets[i] = insertionSort(buckets[i]);
    }

    // Put sorted elements on array
    for (j = 0, i = 0; i < NBUCKET; ++i) {
        struct Node *node;
        node = buckets[i];
        while (node) {
            array[j++] = node->data;
            node = node->next;
        }
    }
    return;
}

void printBuckets(Node *pNode) {
    Node *current = pNode;
    while (current) {
        cout << setw(3) << current->data;
        current = current->next;
    }
}

// Driver code
int main() {
    int array[NARRAY] = {29, 25, 3, 49, 9, 37, 21};
    bucketSort(array);
    cout << "Sorted array in ascending order: ";
    for (int i = 0; i < NARRAY; ++i) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

// The time complexity of the above implementation of bucket sort is O(n+k).
// Best case time complexity: O(n+k)
// Worst case time complexity: O(n^2)
// Average case time complexity: O(n)