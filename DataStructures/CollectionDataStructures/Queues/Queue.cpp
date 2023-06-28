#include "iostream"
using namespace std;

// Queue implementation in C++

#define MAX 5

// Creating a struct for queue
struct queue {
    int front, rear, array[MAX];
};

// Initializing the queue
void createEmptyQueue(struct queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFullQueue(struct queue *q) {
    if (q->rear == MAX - 1)
        return 1;
    else
        return 0;
}

// Check if the queue is empty
int isEmptyQueue(struct queue *q) {
    if (q->front == -1)
        return 1;
    else
        return 0;
}

// Adding elements into queue
void enqueue(struct queue *q, int item) {
    if (isFullQueue(q)) {
        cout << "QUEUE FULL";
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->array[q->rear] = item;
    }
}

// Removing element from queue
void dequeue(struct queue *q) {
    if (isEmptyQueue(q)) {
        cout << "QUEUE EMPTY";
    } else {
        cout << "Element deleted from queue is : " << q->array[q->front] << endl;
        q->front++;
        if (q->front > q->rear)
            q->front = q->rear = -1;
    }
}

// Print elements of queue
void printQueue(struct queue *q) {
    int i = q->front;

    if (isEmptyQueue(q)) {
        cout << "Queue is empty";
    } else {
        cout << "Queue: ";
        for (i = q->front; i < q->rear + 1; i++) {
            cout << q->array[i] << " ";
        }
        cout << endl;
    }
}

// Driver code
int main() {
    struct queue *q = (struct queue *) malloc(sizeof(struct queue));
    createEmptyQueue(q);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    printQueue(q);

    dequeue(q);
    dequeue(q);

    printQueue(q);

    return 0;
}

// Time Complexity: O(1)
// Auxiliary Space: O(1)