#include "iostream"
using namespace std;

// Circular Queue implementation in C++

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
    if (q->front == 0 && q->rear == MAX - 1)
        return 1;
    if (q->front == q->rear + 1)
        return 1;
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
        q->rear = (q->rear + 1) % MAX;
        q->array[q->rear] = item;
    }
}

// Removing element from queue
void dequeue(struct queue *q) {
    if (isEmptyQueue(q)) {
        cout << "QUEUE EMPTY";
    } else {
        cout << "Element deleted from queue is : " << q->array[q->front] << endl;
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front = (q->front + 1) % MAX;
    }
}

// Print elements of queue
void printQueue(struct queue *q) {
    int i = q->front;

    if (isEmptyQueue(q)) {
        cout << "Queue is empty";
    } else {
        cout << "Queue: ";
        while (i != q->rear) {
            cout << q->array[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << q->array[i];
    }
    cout << endl;
}

// Driver code
int main() {
    struct queue *Q = new queue;
    createEmptyQueue(Q);

    enqueue(Q, 1);
    enqueue(Q, 2);
    enqueue(Q, 3);
    enqueue(Q, 4);
    enqueue(Q, 5);

    printQueue(Q);

    dequeue(Q);
    dequeue(Q);

    printQueue(Q);

    enqueue(Q, 6);

    printQueue(Q);

    enqueue(Q, 7);

    printQueue(Q);

    return 0;
}

// Time Complexity: O(1)
// Auxiliary Space: O(1)