#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

void insertFront(Node*& head, int value){

    Node* newNode = new Node;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}


void insertEnd(Node*& head, int value){

    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    newNode->prev = temp;
    temp->next = newNode;
}


void insertPosition(Node*& head, int value, int pos){

    if(pos == 1){
        insertFront(head, value);
        return;
    }

    Node* temp = head;

    for(int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL){
        cout << "Invalid position\n";
        return;
    }

    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}


void deleteFront(Node*& head){

    if (head == NULL)
        return;

    Node* temp = head;

    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

void deleteEnd(Node*& head){

    if(head == NULL)
        return;

    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;

    delete temp;
}

void deletePosition(Node*& head, int pos){

    if(head == NULL)
        return;

    if(pos == 1) {
        deleteFront(head);
        return;
    }

    Node* temp = head;

    for(int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL){
        cout << "Invalid position\n";
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

void displayForward(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void displayBackward(Node* head) {

    if (head == NULL)
        return;

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

void search(Node* head, int value) {

    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {

        if (temp->data == value) {
            cout << "Found at position " << pos << endl;
            return;
        }

        temp = temp->next;
        pos++;
    }

    cout << "Not found\n";
}

int countNodes(Node* head) {

    int count = 0;

    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void update(Node* head, int pos, int value) {

    Node* temp = head;

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid position\n";
        return;
    }

    temp->data = value;
}

void reverseList(Node*& head) {

    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {

        temp = current->prev;

        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;
}

int findMax(Node* head) {

    if (head == NULL)
        return -1;

    int maxValue = head->data;

    Node* temp = head->next;

    while (temp != NULL) {

        if (temp->data > maxValue)
            maxValue = temp->data;

        temp = temp->next;
    }

    return maxValue;
}

int findMin(Node* head) {

    if (head == NULL)
        return -1;

    int minValue = head->data;

    Node* temp = head->next;

    while (temp != NULL) {

        if (temp->data < minValue)
            minValue = temp->data;

        temp = temp->next;
    }

    return minValue;
}


void insertAfterValue(Node*& head, int target, int value) {

    Node* temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Value not found\n";
        return;
    }

    Node* newNode = new Node;

    newNode->data = value;
    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void deleteValue(Node*& head, int value){

    if(head == NULL)
        return;

    Node* temp = head;

    while(temp != NULL && temp->data != value)
        temp = temp->next;

    if(temp == NULL){
        cout << "Value not found\n";
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

int main(){

    Node* head = NULL;

    insertFront(head, 20);
    insertFront(head, 10);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Forward: ";
    displayForward(head);

    cout << "Backward: ";
    displayBackward(head);

    insertPosition(head, 25, 3);

    cout << "After insertion: ";
    displayForward(head);

    deleteFront(head);

    cout << "After delete front: ";
    displayForward(head);

    deleteEnd(head);

    cout << "After delete end: ";
    displayForward(head);

    reverseList(head);

    cout << "After reverse: ";
    displayForward(head);

    return 0;
}