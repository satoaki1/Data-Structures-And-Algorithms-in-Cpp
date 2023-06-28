#include "iostream"
using namespace std;

// Deque implementation in C++

#define MAX 10

// Creating a struct for deque
struct deque {
    int arr[MAX];
    int front;
    int rear;
    int size;
};

// Initializing the deque
void createDeque(struct deque *d) {
    d->front = -1;
    d->rear = 0;
    d->size = 0;
}

// Check if the deque is full
int isFullDeque(struct deque *d) {
    return ((d->front == 0 && d->rear == MAX - 1) || d->front == d->rear + 1);
}

// Check if the deque is empty
int isEmptyDeque(struct deque *d) {
    return (d->front == -1);
}

// Adding elements into deque at front
void insertFront(struct deque *d, int key) {
    if (isFullDeque(d)) {
        cout << "Deque Overflow";
        return;
    }

    if (d->front == -1) {
        d->front = 0;
        d->rear = 0;
    } else if (d->front == 0)
        d->front = MAX - 1;
    else
        d->front = d->front - 1;

    d->arr[d->front] = key;
    d->size = d->size + 1;
}

// Adding elements into deque at rear
void insertRear(struct deque *d, int key) {
    if (isFullDeque(d)) {
        cout << "Deque Overflow";
        return;
    }

    if (d->front == -1) {
        d->front = 0;
        d->rear = 0;
    } else if (d->rear == MAX - 1)
        d->rear = 0;
    else
        d->rear = d->rear + 1;

    d->arr[d->rear] = key;
    d->size = d->size + 1;
}

// Removing elements from deque at front
void deleteFront(struct deque *d) {
    if (isEmptyDeque(d)) {
        cout << "Deque Underflow";
        return;
    }

    if (d->front == d->rear) {
        d->front = -1;
        d->rear = -1;
    } else if (d->front == MAX - 1)
        d->front = 0;
    else
        d->front = d->front + 1;

    d->size = d->size - 1;
}

// Removing elements from deque at rear
void deleteRear(struct deque *d) {
    if (isEmptyDeque(d)) {
        cout << "Deque Underflow";
        return;
    }

    if (d->front == d->rear) {
        d->front = -1;
        d->rear = -1;
    } else if (d->rear == 0)
        d->rear = MAX - 1;
    else
        d->rear = d->rear - 1;

    d->size = d->size - 1;
}

// Returns the front element of deque
int getFront(struct deque *d) {
    if (isEmptyDeque(d)) {
        cout << "Deque Underflow";
        return -1;
    }
    return d->arr[d->front];
}

// Returns the rear element of deque
int getRear(struct deque *d) {
    if (isEmptyDeque(d) || d->rear < 0) {
        cout << "Deque Underflow";
        return -1;
    }
    return d->arr[d->rear];
}

// Printing the elements of deque
void printDeque(struct deque *d) {
    if (isEmptyDeque(d)) {
        cout << "Deque Underflow";
        return;
    }

    cout << "Deque: ";
    int count = (d->rear + MAX - d->front) % MAX + 1;
    for (int i = 0; i < count; i++) {
        int index = (d->front + i) % MAX;
        cout << d->arr[index] << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    struct deque d;
    createDeque(&d);

    insertFront(&d, 5);
    insertRear(&d, 10);
    insertRear(&d, 15);
    printDeque(&d);

    deleteFront(&d);
    printDeque(&d);

    deleteRear(&d);
    printDeque(&d);

    cout << "Front element is: " << getFront(&d) << endl;
    cout << "Rear element is: " << getRear(&d) << endl;

    return 0;
}

// Time Complexity: O(1)
// Auxiliary Space: O(1)