#include<iostream>
using namespace std;

class Queue{
    int a[100];
    int front,rear,size;

public:
    Queue(int n){
        size=n;
        front=0;
        rear=-1;
    }

void join(int x){
    if(rear==size-1)
        cout<<"Queue Full\n";
    else{
        rear++;
        a[rear]=x;
    }
}

void serve(){
    if(front>rear)
        cout<<"Queue Empty\n";
    else{
        cout<<"Served: "<<a[front]<<"\n";
        front++;
    }
}

void display(){
    if(front>rear)
        cout<<"Queue Empty\n";
    else{
        cout<<"Queue: ";
        for(int i=front;i<=rear;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}
};

int main(){
    int n,ch,x;
    cin>>n;
    Queue q(n);
    do{
        cout<<"1.Join 2.Serve 3.Display 0.Exit\n";
        cin>>ch;

        if(ch==1){
            cin>>x;
            q.join(x);
        }
        else if(ch==2)
            q.serve();
        else if(ch==3)
            q.display();

    }while(ch!=0);
    return 0;
}