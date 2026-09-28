#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertFront(Node*& head, int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void deleteFront(Node*& head) {
    if (head == NULL)
        return;

    Node* temp = head;
    head = head->next;

    delete temp;
}

void deleteEnd(Node*& head) {
    if (head == NULL)
        return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

void reverseList(Node*& head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {

        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    head = prev;
}

int main() {

    Node* head = NULL;

    insertFront(head, 30);
    insertFront(head, 20);
    insertFront(head, 10);

    cout << "Linked List: ";
    display(head);

    insertEnd(head, 40);

    cout << "After insertion at end: ";
    display(head);

    deleteFront(head);

    cout << "After deletion from front: ";
    display(head);

    deleteEnd(head);

    cout << "After deletion from end: ";
    display(head);

    reverseList(head);

    cout << "After reverse: ";
    display(head);

    return 0;
}