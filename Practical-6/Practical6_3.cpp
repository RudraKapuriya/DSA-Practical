#include<iostream>
#include<stack>
using namespace std;

int priority(char ch)
{
    if(ch == '*' || ch == '/')
    return 2;

     if(ch == '+' || ch == '-')
    return 1;

    return 0;


    
}

string inftopost(string infix)
{
    stack<char> s;
    string postfix = "";          //to store postfix expression 

    for(char ch : infix)         // store only char of user given expreesion 
    {
        if(isdigit(ch))
        {
            postfix += ch;
        }

        else if (ch =='(')
        {
            s.push(ch);
        }

        else if(ch==')')
        {
             while(s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            s.pop();
        }

        else
         {
            while(!s.empty() &&
                  priority(s.top()) >= priority(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

     while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    string infix;

    cout<<"enter your expreesion:";
    cin>>infix;

    cout<<"postfix: "<<inftopost(infix);

    return 0;
}
