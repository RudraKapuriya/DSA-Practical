#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createNode(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = nullptr;

    return newNode;
}

void display(Node* head)
{
    if (head == nullptr)
    {
        cout << "Queue is Empty!" << endl;
        return;
    }

    Node* temp = head;

    cout << "Current Queue: ";

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void insertFront(Node** head, int value)
{
    Node* newNode = createNode(value);

    newNode->next = *head;
    *head = newNode;
}

void insertEnd(Node** head, int value)
{
    Node* newNode = createNode(value);

    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }

    Node* temp = *head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtPosition(Node** head, int value, int position)
{
    if (position < 1)
    {
        cout << "Invalid Position!" << endl;
        return;
    }

    if (position == 1)
    {
        insertFront(head, value);
        return;
    }

    Node* newNode = createNode(value);
    Node* temp = *head;

    for (int i = 1; i < position - 1; i++)
    {
        if (temp == nullptr)
        {
            cout << "Invalid Position is beyond queue length." << endl;
            delete newNode;
            return;
        }

        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Invalid Position is beyond queue length." << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteByValue(Node** head, int value)
{
    if (*head == nullptr)
    {
        cout << "Queue is Empty. Deletion not Possible!" << endl;
        return;
    }

    Node* temp = *head;
    Node* prev = nullptr;

    if (temp->data == value)
    {
        *head = temp->next;
        delete temp;

        cout << "Patient token deleted." << endl;
        return;
    }

    while (temp != nullptr && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Patient token not found." << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;

    cout << "Patient token deleted." << endl;
}

void reversePrint(Node* head)
{
    if (head == nullptr)
    {
        return;
    }

    reversePrint(head->next);

    cout << head->data << " ";
}

int main()
{
    Node* head = nullptr;

    int choice;
    int token;
    int position;

    while (true)
    {
        cout << "\n-- Hospital Patient Queue --" << endl;

        cout << "1. Insert Critical Patient at Front" << endl;
        cout << "2. Insert Routine Patient at End" << endl;
        cout << "3. Insert Priority Patient at Position" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Delete Patient Token" << endl;
        cout << "6. Reverse Patient Token" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\nEnter Patient Token: ";
                cin >> token;

                insertFront(&head, token);
                display(head);

                break;

            case 2:
                cout << "\nEnter Patient Token: ";
                cin >> token;

                insertEnd(&head, token);
                display(head);

                break;

            case 3:
                cout << "Enter Patient Token: ";
                cin >> token;

                cout << "Enter Position: ";
                cin >> position;

                insertAtPosition(&head, token, position);
                display(head);

                break;

            case 4:
                display(head);
                break;

            case 5:
                cout << "Enter Token to Delete: ";
                cin >> token;

                deleteByValue(&head, token);
                break;

            case 6:
                cout << "Reverse Queue: ";
                reversePrint(head);
                cout << endl;

                break;

            case 7:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Enter valid Choice!" << endl;
        }
    }

    return 0;
}
