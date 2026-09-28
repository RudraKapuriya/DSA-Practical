#include <iostream>
using namespace std;

class stack {

    
    class Node {
    public:
        int data;
        Node* next;

        Node(int x) {
            data = x;
            next = nullptr;
        }
    };

    Node* top;

public:


    stack() {
        top = nullptr;
    }

    // PUSH
    void push(int x) {

        Node* newNode = new Node(x);

        newNode->next = top;
        top = newNode;

        cout << x << " th new webpage visited\n\n";
        cout << top->data << " th current page\n\n";

        cout << "--------------------------\n";
    }

    
    void pop() {

        if (top == nullptr) {
            cout << "underflow, page do not exist\n";
        }
        else {

            cout << top->data << " th page is remove\n\n";

            Node* temp = top;

            top = top->next;

            delete temp;

            if (top == nullptr) {
                cout << "pages does not exist\n";
            }
            else {
                cout << top->data << " th current page\n\n";
            }
        }

        cout << "----------------------------\n";
    }
};

int main()
{
    stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);

    s.pop();

    s.push(9);

    s.pop();
    s.pop();

    s.push(10);

    s.pop();

    return 0;
}