#include "iostream"
using namespace std;

// Circular Linked List implementation in C++

// Creating a node
struct Node {
    int value;
    Node* next;
};

// function to insert new node at the beginning
void insertAtBeginning(Node** head_ref, int new_value) {
    // allocate node
    Node* new_node = new Node();

    // put in the value
    new_node->value = new_value;

    // link the old list off the new node
    new_node->next = (*head_ref);

    // if list is not NULL, then set the prev of head as new node
    if (*head_ref != NULL)
        (*head_ref)->next = new_node;

    // move the head to point to the new node
    (*head_ref) = new_node;
}

// function to insert new node at the end
void insertAtEnd(Node** head_ref, int new_value) {
    // allocate node
    Node* new_node = new Node();

    Node* last = *head_ref; // used in step 5

    // put in the value
    new_node->value = new_value;

    // this new node is going to be the last node, so make next of it as head
    new_node->next = *head_ref;

    // if the linked list is empty, then make the new node as head
    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    // else traverse till the last node
    while (last->next != *head_ref)
        last = last->next;

    // change the next of last node
    last->next = new_node;

    return;
}

// function to insert a new node after a given node
void insertAfter(Node* prev_node, int new_value) {
    // check if the given prev_node is NULL
    if (prev_node == NULL) {
        cout << "the given previous node cannot be NULL";
        return;
    }

    // allocate new node
    Node* new_node = new Node();

    // put in the value
    new_node->value = new_value;

    // make next of new node as next of prev_node
    new_node->next = prev_node->next;

    // move the next of prev_node as new_node
    prev_node->next = new_node;
}

// function to delete a node
void deleteNode(Node** head_ref, int key) {
    // if linked list is empty
    if (*head_ref == NULL)
        return;

    // if the list contains only a single node
    if ((*head_ref)->value == key && (*head_ref)->next == *head_ref) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    Node *last = *head_ref, *d;

    // if head is to be deleted
    if ((*head_ref)->value == key) {
        // find the last node of the list
        while (last->next != *head_ref)
            last = last->next;

        // point last node to the next of head or second node of the list
        last->next = (*head_ref)->next;
        free(*head_ref);
        *head_ref = last->next;
    }

    // else search for the key to be deleted, keep track of the previous node as we need to change 'prev->next'
    else {
        d = *head_ref;
        while (d->next != *head_ref) {
            // if node to be deleted is found
            if (d->next->value == key) {
                // delete the node by adjusting the previous node's next pointer
                d->next = d->next->next;
                free(d->next);
                return;
            }
            d = d->next;
        }
    }

    // else check if the key is present in the list
    while (last->next != *head_ref && last->next->value != key)
        last = last->next;

    // if the key was found, delete it
    if (last->next->value == key) {
        Node* temp = last->next;
        last->next = temp->next;
        free(temp);
    }
    else
        cout << "the given key is not found";
}

// function to print nodes in a given circular linked list
void displayList(Node* node) {
    Node* temp = node;

    // if list is empty, return
    if (node == NULL) {
        cout << "the list is empty";
        return;
    }

    // else, print the list while end of the list is not reached
    do {
        cout << temp->value << " ";
        temp = temp->next;
    } while (temp != node);
}

// driver code
int main() {
    Node* head = NULL;

    // insert nodes in circular fashion
    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAtBeginning(&head, 4);
    insertAfter(head->next->next, 5);

    cout << "the circular linked list is: ";
    displayList(head);
    cout << endl;

    deleteNode(&head, 4);
    deleteNode(&head, 5);

    cout << "\nthe circular linked list after deletion of nodes is: ";
    displayList(head);
    cout << endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)