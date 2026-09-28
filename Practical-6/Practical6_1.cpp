#include <iostream>
using namespace std;
const int n = 15;

class stack{

    int arr[n];
    int top;


    public:
    stack(){
        top = -1;
    }

    void push(int x)
    {
        if(top == n-1)
        {
            cout<<"overflow, no more tray are allow";
        }

        else{
            top++;
            arr[top]=x;
            cout<< x <<" th new tray is added\n\n";
            cout<< arr[top] <<" th current plate\n\n";
        }
        cout<<"--------------------------\n";
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"underflow,trays are not exist ";
        }

        else{
            cout<< arr[top]<<"th  tray is taken \n\n";
         
            top--;

            if(top == -1)
            {
                cout<<"plates does not exist";
            }
            else{
             cout<< arr[top]<< "th current plate\n\n";
            }
        }
        
        cout<<"----------------------------\n";
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
}