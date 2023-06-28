#include "stdlib.h"
#include "iostream"
using namespace std;

// Stack implementation in C++


#define MAX 10

// Creating a struct stack
struct stack {
    int top;
    int array[MAX];
};
typedef struct stack st;

// Initializing the stack
void createEmptyStack(st *s) {
    s->top = -1;
}

// Check if the stack is full
int isFullStack(st *s) {
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

// Check if the stack is empty
int isEmptyStack(st *s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}

// Adding elements into stack
void push(st *s, int item) {
    if (isFullStack(s)) {
        cout << "STACK FULL";
    } else {
        s->top++;
        s->array[s->top] = item;
    }
}

// Removing element from stack
void pop(st *s) {
    if (isEmptyStack(s)) {
        cout << "\n STACK EMPTY \n";
    } else {
        cout << "Item popped= " << s->array[s->top];
        s->top--;
    }
    cout << endl;
}

// Print elements of stack
void printStack(st *s) {
    cout << "Stack: ";
    for (int i = 0; i <= s->top; i++) {
        cout << s->array[i] << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    int ch;
    st *s = (st *) malloc(sizeof(st));

    createEmptyStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);

    printStack(s);

    pop(s);

    cout << "\nAfter popping out\n";
    printStack(s);
}

// Time Complexity: O(1)
// Auxiliary Space: O(1)