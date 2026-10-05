#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int x){
        data=x;
        next=NULL;
    }
};

class Queue{
    Node *front,*rear;
public:
    Queue(){
        front=rear=NULL;
    }

void arrive(int x){
    Node *n=new Node(x);

    if(rear==NULL){
        front=rear=n;
    }
    else{
        rear->next=n;
        rear=n;
    }
}

void attend(){
    if(front==NULL){
        cout<<"Queue Empty\n";
        return;
    }
    Node *p=front;
    cout<<"Attended: "<<p->data<<"\n";
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }
    delete p;
}

void display(){
    if(front==NULL){
        cout<<"Queue Empty\n";
        return;
    }

    cout<<"Queue: ";
    Node *current=front;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<"\n";
}
};

int main(){
    Queue q;
    int ch,x;

    do{
        cout<<"1.Arrive 2.Attend 3.Display 0.Exit\n";
        cin>>ch;

        if(ch==1){
            cin>>x;
            q.arrive(x);
        }
        else if(ch==2)
            q.attend();
        else if(ch==3)
            q.display();

    }while(ch!=0);

    return 0;
}