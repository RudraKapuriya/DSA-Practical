#include <iostream>
using namespace std;

struct Node
{
    int id, priority;
    Node *prev, *next;
};

Node *head = NULL, *tail = NULL, *current = NULL;
int totalLinks = 0;

// Find ticket
Node* find(int id)
{
    Node *p = head;
    while(p != NULL)
    {
        if(p->id == id) return p;
        p = p->next;
    }
    return NULL;
}

// Insert ticket according to priority
void NEW(int id, int pr)
{
    Node *n = new Node{id, pr, NULL, NULL};
    int links = 0;

    if(head == NULL)
        head = tail = current = n;

    else if(pr > head->priority)
    {
        n->next = head;
        head->prev = n;
        head = n;
        links = 2;
    }

    else
    {
        Node *p = head;

        while(p->next != NULL && p->next->priority >= pr)
            p = p->next;

        if(p == tail)
        {
            n->prev = tail;
            tail->next = n;
            tail = n;
            links = 2;
        }
        else
        {
            n->next = p->next;
            n->prev = p;
            p->next->prev = n;
            p->next = n;
            links = 4;
        }
    }

    totalLinks += links;
    cout << "Links changed: " << links << endl;
}

// Delete ticket
void RESOLVE(int id)
{
    Node *p = find(id);

    if(p == NULL)
    {
        cout << "Invalid ID\nLinks changed: 0\n";
        return;
    }

    int links = 0;

    if(p == head && p == tail)
    {
        head = tail = current = NULL;
    }
    else if(p == head)
    {
        head = head->next;
        head->prev = NULL;
        if(current == p) current = head;
        links = 2;
    }
    else if(p == tail)
    {
        tail = tail->prev;
        tail->next = NULL;
        if(current == p) current = tail;
        links = 2;
    }
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        if(current == p) current = p->next;
        links = 2;
    }

    delete p;
    totalLinks += links;

    cout << "Links changed: " << links << endl;
}

// Change priority
void CHANGE(int id, int newPr)
{
    Node *p = find(id);

    if(p == NULL)
    {
        cout << "Invalid ID\nLinks changed: 0\n";
        return;
    }

    bool wasCurrent = (current == p);

    // Remove
    if(p == head && p == tail)
    {
        p->priority = newPr;
        cout << "Links changed: 0\n";
        return;
    }
    else if(p == head)
    {
        head = p->next;
        head->prev = NULL;
        totalLinks += 2;
    }
    else if(p == tail)
    {
        tail = p->prev;
        tail->next = NULL;
        totalLinks += 2;
    }
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        totalLinks += 2;
    }

    p->prev = p->next = NULL;
    p->priority = newPr;

    // Reinsert
    int links = 0;

    if(newPr > head->priority)
    {
        p->next = head;
        head->prev = p;
        head = p;
        links = 2;
    }
    else
    {
        Node *q = head;

        while(q->next != NULL && q->next->priority >= newPr)
            q = q->next;

        if(q == tail)
        {
            p->prev = tail;
            tail->next = p;
            tail = p;
            links = 2;
        }
        else
        {
            p->next = q->next;
            p->prev = q;
            q->next->prev = p;
            q->next = p;
            links = 4;
        }
    }

    if(wasCurrent) current = p;

    totalLinks += links;

    cout << "Links changed: " << links + 2 << endl;
}

// Display forward
void SHOW()
{
    Node *p = head;

    while(p != NULL)
    {
        cout << p->id << "(" << p->priority << ") ";
        p = p->next;
    }
    cout << endl;
}

// Display reverse
void SHOW_REVERSE()
{
    Node *p = tail;

    while(p != NULL)
    {
        cout << p->id << "(" << p->priority << ") ";
        p = p->prev;
    }
    cout << endl;
}

// Next
void NEXT()
{
    if(current && current->next)
        current = current->next;
    else
        cout << "Cannot move NEXT\n";
}

// Previous
void PREVIOUS()
{
    if(current && current->prev)
        current = current->prev;
    else
        cout << "Cannot move PREVIOUS\n";
}

// Current ticket
void CURRENT()
{
    if(current)
        cout << current->id << "(" << current->priority << ")\n";
    else
        cout << "No current ticket\n";
}

int main()
{
    int ch, id, pr;

    do
    {
        cout << "\n1.NEW  2.NEXT  3.PREVIOUS  4.RESOLVE";
        cout << "\n5.CHANGE  6.SHOW  7.SHOW_REVERSE  8.CURRENT  9.EXIT";
        cout << "\nChoice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cin >> id >> pr;
                if(pr >= 1 && pr <= 5)
                    NEW(id, pr);
                else
                    cout << "Invalid priority\n";
                break;

            case 2: NEXT(); break;
            case 3: PREVIOUS(); break;

            case 4:
                cin >> id;
                RESOLVE(id);
                break;

            case 5:
                cin >> id >> pr;
                if(pr >= 1 && pr <= 5)
                    CHANGE(id, pr);
                else
                    cout << "Invalid priority\n";
                break;

            case 6: SHOW(); break;
            case 7: SHOW_REVERSE(); break;
            case 8: CURRENT(); break;

            case 9:
                cout << "Total link modifications: "
                     << totalLinks << endl;
        }

    } while(ch != 9);

    return 0;
}