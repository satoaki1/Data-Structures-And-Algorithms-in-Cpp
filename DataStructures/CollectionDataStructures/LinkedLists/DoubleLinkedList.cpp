#include <iostream>
using namespace std;

// Double Linked List implementation in C++

// Creating a node
struct Node {
    int value;
    Node* next;
    Node* prev;
};

// insert node at the beginning of the list
void insertAtTheBegin(Node** start_ref, int value) {
    if (*start_ref == NULL) {
        Node* new_node = new Node();
        new_node->value = value;
        new_node->next = new_node->prev = new_node;
        *start_ref = new_node;
        return;
    }

    Node* last = (*start_ref)->prev;

    Node* new_node = new Node();
    new_node->value = value;

    new_node->next = *start_ref;

    (*start_ref)->prev = new_node;

    new_node->prev = last;

    last->next = new_node;
}

// insert node at the end of the list
void insertAtTheEnd(Node** start_ref, int value) {
    if (*start_ref == NULL) {
        Node* new_node = new Node();
        new_node->value = value;
        new_node->next = new_node->prev = new_node;
        *start_ref = new_node;
        return;
    }

    Node* last = (*start_ref)->prev;

    Node* new_node = new Node();
    new_node->value = value;

    new_node->prev = last;

    last->next = new_node;

    new_node->next = *start_ref;

    (*start_ref)->prev = new_node;
}

// insert node at the given index of the list
void insertAtIndex(Node** start_ref, int index, int value) {
    if (index < 0) {
        cout << "Invalid Index";
        return;
    }

    if (index == 0) {
        insertAtTheBegin(start_ref, value);
        return;
    }

    Node* new_node = new Node();
    new_node->value = value;

    Node* temp = *start_ref;

    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
        if (temp == *start_ref) {
            cout << "Invalid Index";
            return;
        }
    }

    new_node->next = temp->next;

    temp->next = new_node;

    new_node->prev = temp;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

// delete node from the list
void deleteNode(Node** start_ref, int key) {
    if (*start_ref == NULL) {
        cout << "List is empty";
        return;
    }

    if ((*start_ref)->value == key && (*start_ref)->next == *start_ref) {
        free(*start_ref);
        *start_ref = NULL;
        return;
    }

    Node* last = (*start_ref)->prev, *temp;

    if ((*start_ref)->value == key) {
        temp = *start_ref;
        *start_ref = (*start_ref)->next;
        last->next = *start_ref;
        (*start_ref)->prev = last;
        free(temp);
        return;
    }

    if (last->value == key) {
        temp = last;
        last = last->prev;
        last->next = *start_ref;
        (*start_ref)->prev = last;
        free(temp);
        return;
    }

    temp = *start_ref;

    while (temp->value != key) {
        if (temp->next == *start_ref) {
            cout << "Given node is not found in the list";
            return;
        }

        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

// delete node at the first index of the list
void deleteAtFirst(Node** start_ref) {
    if (*start_ref == NULL) {
        cout << "List is empty";
        return;
    }

    if ((*start_ref)->next == *start_ref) {
        free(*start_ref);
        *start_ref = NULL;
        return;
    }

    Node* last = (*start_ref)->prev;

    Node* temp = *start_ref;

    *start_ref = (*start_ref)->next;

    last->next = *start_ref;

    (*start_ref)->prev = last;

    free(temp);
}

// delete node at the last index of the list
void deleteAtLast(Node** start_ref) {
    if (*start_ref == NULL) {
        cout << "List is empty";
        return;
    }

    if ((*start_ref)->next == *start_ref) {
        free(*start_ref);
        *start_ref = NULL;
        return;
    }

    Node* last = (*start_ref)->prev;

    Node* temp = last;

    last = last->prev;

    last->next = *start_ref;

    (*start_ref)->prev = last;

    free(temp);
}

// delete node at the given index of the list
void deleteAtIndex(Node** start_ref, int index) {
    if (*start_ref == NULL) {
        cout << "List is empty";
        return;
    }

    if (index < 0) {
        cout << "Invalid Index";
        return;
    }

    if (index == 0) {
        deleteAtFirst(start_ref);
        return;
    }

    Node* last = (*start_ref)->prev, *temp;

    if (index == 0) {
        temp = *start_ref;
        *start_ref = (*start_ref)->next;
        last->next = *start_ref;
        (*start_ref)->prev = last;
        free(temp);
        return;
    }

    temp = *start_ref;

    for (int i = 0; i < index; i++) {
        temp = temp->next;
        if (temp->next == *start_ref) {
            cout << endl << "Invalid Index";
            return;
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

// search node in the list
void searchNode(Node* start, int key) {
    Node* temp = start;

    int pos = 0;

    if (start != NULL) {
        do {
            pos++;
            if (temp->value == key) {
                cout << endl << "Element " << key << " is found at position " << pos << endl;
                return;
            }
            temp = temp->next;
        } while (temp != start);
    }

    cout << "Element " << key << " is not found in the list" << endl;
}

// sort the list
void sortList(Node** start_ref) {
    Node* temp = *start_ref, *index = NULL;
    int value;

    if (*start_ref == NULL) {
        cout << "List is empty";
        return;
    }
    else {
        do {
            index = temp->next;
            while (index != *start_ref) {
                if (temp->value > index->value) {
                    value = temp->value;
                    temp->value = index->value;
                    index->value = value;
                }
                index = index->next;
            }
            temp = temp->next;
        } while (temp->next != *start_ref);
    }
}

// print the list
void printList(Node* start) {
    Node* temp = start;

    if (start != NULL) {
        do {
            cout << temp->value << " ";
            temp = temp->next;
        } while (temp != start);
    }
    cout << endl;
}

// driver code
int main() {
    Node* start = NULL;

    insertAtTheBegin(&start, 5);
    insertAtTheBegin(&start, 4);
    insertAtTheBegin(&start, 3);
    insertAtTheBegin(&start, 2);
    insertAtTheBegin(&start, 1);

    cout << "Circular doubly linked list before insertion: ";
    printList(start);

    insertAtTheEnd(&start, 6);
    insertAtTheEnd(&start, 7);
    insertAtTheEnd(&start, 8);
    insertAtTheEnd(&start, 9);
    insertAtTheEnd(&start, 10);

    cout << "\nCircular doubly linked list after insertion: ";
    printList(start);

    insertAtIndex(&start, 0, 0);
    insertAtIndex(&start, 5, 5);
    insertAtIndex(&start, 10, 10);

    cout << "\nCircular doubly linked list after insertion: ";
    printList(start);

    deleteAtFirst(&start);
    deleteAtLast(&start);
    deleteAtIndex(&start, 0);
    deleteAtIndex(&start, 5);
    deleteAtIndex(&start, 8);

    cout << "\nCircular doubly linked list after deletion: ";
    printList(start);

    searchNode(start, 5);
    searchNode(start, 10);
    searchNode(start, 15);

    sortList(&start);

    cout << "\nCircular doubly linked list after sorting: ";
    printList(start);

    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)