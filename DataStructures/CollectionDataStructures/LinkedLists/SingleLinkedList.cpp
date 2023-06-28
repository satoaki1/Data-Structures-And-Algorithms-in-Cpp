#include "stdlib.h"
#include "iostream"
using namespace std;

// Single Linked List implementation in C++

// Creating a node
struct Node {
    int value;
    Node* next;
};

// function to insert new node at beginning
void insertAtBeginning(Node** head_ref, int new_value) {
    // allocate node
    Node* new_node = new Node();

    // put in the value
    new_node->value = new_value;

    // link the old list off the new node
    new_node->next = (*head_ref);

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

    // this new node is going to be the last node, so make next of it as NULL
    new_node->next = NULL;

    // if the linked list is empty, then make the new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // else traverse till the last node
    while (last->next != NULL)
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
    // store head node
    Node* temp = *head_ref;
    Node* prev = NULL;

    // if head node itself holds the key to be deleted
    if (temp != NULL && temp->value == key) {
        *head_ref = temp->next; // changed head
        free(temp); // free old head
        return;
    }

    // else search for the key to be deleted, keep track of the previous node as we need to change 'prev->next'
    while (temp != NULL && temp->value != key) {
        prev = temp;
        temp = temp->next;
    }

    // if key was not present in linked list
    if (temp == NULL) return;

    // unlink the node from linked list
    prev->next = temp->next;

    // free memory
    free(temp);
}

// function to delete a linked list
void deleteLinkedList(Node** head_ref) {
    // deref head_ref to get the real head
    Node* current = *head_ref;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    // deref head_ref to affect the real head back in the caller
    *head_ref = NULL;
}

// function to delete a node at a given position
void deleteNodeAtGivenPos(Node** head_ref, int position) {
    // if linked list is empty
    if (*head_ref == NULL)
        return;

    // store head node
    Node* temp = *head_ref;

    // if head needs to be removed
    if (position == 0) {
        // change head
        *head_ref = temp->next;

        // free old head
        free(temp);
        return;
    }

    // find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // if position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // node temp->next is the node to be deleted
    // store pointer to the next of node to be deleted
    Node* next = temp->next->next;

    // unlink the node from linked list
    free(temp->next); // free memory

    temp->next = next; // unlink the deleted node from list
}

// function to delete a node at first of linked list
void deleteFirstNode(Node** head_ref) {
    // if linked list is empty
    if (*head_ref == NULL)
        return;

    // store head node
    Node* temp = *head_ref;

    // change head
    *head_ref = temp->next;

    // free old head
    free(temp);
    return;
}

// function to delete a node at last of linked list
void deleteLastNode(Node** head_ref) {
    // if linked list is empty
    if (*head_ref == NULL)
        return;

    // store head node
    Node* temp = *head_ref;

    // if head needs to be removed
    if (temp->next == NULL) {
        // change head
        *head_ref = temp->next;

        // free old head
        free(temp);
        return;
    }

    // find previous node of the node to be deleted
    while (temp->next->next != NULL)
        temp = temp->next;

    // node temp->next is the node to be deleted
    // store pointer to the next of node to be deleted
    Node* next = temp->next->next;

    // unlink the node from linked list
    free(temp->next); // free memory

    temp->next = next; // unlink the deleted node from list
}

// function to get count of nodes in linked list
int getCount(Node* head) {
    int count = 0; // initialize count
    Node* current = head; // initialize current
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// function to search a given key in linked list
bool search(Node* head, int key) {
    Node* current = head; // initialize current
    while (current != NULL) {
        if (current->value == key)
            return true;
        current = current->next;
    }
    return false;
}

// function to get Nth node in linked list
int getNth(Node* head, int index) {
    Node* current = head; // initialize current
    int count = 0; // index of current node

    while (current != NULL) {
        if (count == index)
            return (current->value);
        count++;
        current = current->next;
    }

    /* if we get to this line, the caller was asking for a non-existent element so we assert fail */
    assert(0);
}

// function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->value << " ";
        node = node->next;
    }
}

// driver code
int main() {
    // start with the empty list
    Node *head = NULL;

    // insert 6 at the beginning. so linked list becomes 6->NULL
    insertAtBeginning(&head, 6);

    // insert 7 at the beginning. so linked list becomes 7->6->NULL
    insertAtBeginning(&head, 7);

    // insert 1 at the beginning. so linked list becomes 1->7->6->NULL
    insertAtBeginning(&head, 1);

    // insert 4 at the end. so linked list becomes 1->7->6->4->NULL
    insertAtEnd(&head, 4);

    // insert 8, after 7. so linked list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

    cout << "Created Linked list is: ";
    printList(head);

    // delete node with value 1. so linked list becomes 7->8->6->4->NULL
    deleteNode(&head, 1);

    cout << "\nLinked List after Deletion of 1: ";
    printList(head);

    // delete node with value 4. so linked list becomes 7->8->6->NULL
    deleteNode(&head, 4);

    cout << "\nLinked List after Deletion of 4: ";
    printList(head);

    // delete node with value 8. so linked list becomes 7->6->NULL
    deleteNode(&head, 8);

    cout << "\nLinked List after Deletion of 8: ";
    printList(head);

    // delete node at position 2. so linked list becomes 7->NULL
    deleteNodeAtGivenPos(&head, 2);

    cout << "\nLinked List after Deletion at position 2: ";
    printList(head);

    // delete first node. so linked list becomes NULL
    deleteFirstNode(&head);

    cout << "\nLinked List after Deletion of first node: ";
    printList(head);

    // delete last node. so linked list becomes NULL
    deleteLastNode(&head);

    cout << "\nLinked List after Deletion of last node: ";
    printList(head);

    cout << endl;
}

// Time Complexity: O(n) where n is the number of nodes in linked list.
// Space Complexity: O(1)