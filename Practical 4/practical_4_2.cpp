#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createNode(int value)
{
    Node* newNode;

    newNode = new Node;

    newNode->data = value;
    newNode->next = nullptr;

    return newNode;
}



void insertEnd(Node** head, int value)
{
    Node* newNode;
    Node* temp;

    newNode = createNode(value);

    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}



void display(Node* head)
{
    Node* temp;

    if (head == nullptr)
    {
        cout << "Queue is Empty!" << endl;
        return;
    }

    temp = head;

    cout << "Queue from Front to Back: ";

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


void deleteByValue(Node** head, int value)
{
    Node* temp;
    Node* prev;

    if (*head == nullptr)
    {
        cout << "Queue is Empty. Deletion not Possible!" << endl;
        return;
    }

    temp = *head;
    prev = nullptr;


    if (temp->data == value)
    {
        *head = temp->next;
        delete temp;

        cout << "Patient token " << value << " deleted." << endl;
        return;
    }

    while (temp != nullptr && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Patient token " << value << " not found." << endl;
        return;
    }

    prev->next = temp->next;

    delete temp;

    cout << "Patient token " << value << " deleted." << endl;
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

    while (true)
    {
        cout << "\n-- Hospital Patient Queue --" << endl;

        cout << "1. Insert Patient Token" << endl;
        cout << "2. Display Queue (Front to Back)" << endl;
        cout << "3. Delete Patient Token" << endl;
        cout << "4. Reverse Print Queue" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:

                cout << "Enter Patient Token: ";
                cin >> token;

                insertEnd(&head, token);
                display(head);

                break;


            case 2:

                display(head);

                break;


            case 3:

                cout << "Enter Token to Delete: ";
                cin >> token;

                deleteByValue(&head, token);
                display(head);

                break;


            case 4:

                if (head == nullptr)
                {
                    cout << "Queue is Empty!" << endl;
                }
                else
                {
                    cout << "Queue from Back to Front: ";

                    reversePrint(head);

                    cout << endl;
                }

                break;


            case 5:

                return 0;


            default:

                cout << "Enter Valid Choice!" << endl;
        }
    }

    return 0;
}
