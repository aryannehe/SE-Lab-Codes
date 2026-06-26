/*
DSL Group D Assignment 1
Neeti Kurulkar
SE A 21038

Implement C++ program for expression conversion as infix to postfix and its
evaluation using stack based on given conditions:

1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
*/


#include <iostream>
#include <string>
using namespace std;

const int Max=50;

//Class to create a stack
class Stack
{
    public:
        int top;
        char arr[Max];
        Stack()
        {
            top = -1;
        }
        
        //checking if stack is empty
        bool is_empty()
        {
            if(top==-1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        
        //checking if stack is full
        bool is_full()
        {
            if(top==Max-1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        
        //pushing element in stack
        void push(char x)
        {
            if(is_full())
            {
                cout << "Stack is full!";
            }
            else
            {
                top++;
                arr[top] = x; 
            }
        }
        
        //popping element from stack
        void pop()
        {
            if(is_empty())
            {
                cout << "Stack is empty!";
            }
            else
            {
                arr[top] = 0;
                top--;
            }
        }
        
        //returns top element in stack
        char top_element()
        {
            return arr[top];
        }
};

//Function to check if character is an operator
bool is_operator(char c)
{
    if(c=='+' || c=='-' || c=='/' || c=='*' )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//function to check precedence of operator
int precedence(char c)
{


    if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

//function to convert from infix to postfix
string infix_to_postfix(Stack s, string infix)
{
    string postfix;
    
    for(int i=0; i<infix.length(); i++) //iterating through entire infix expression
    {
        if( (infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z') )
        {
            //if character is an alphabet, directly paste into postfix expression
            postfix += infix[i];
        }
        else if(infix[i]=='(')
        {
            //if character is an opening bracket, directly push into stack
            s.push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while((s.top_element()!='(') && (!s.is_empty()))
            {
                //pop everything between two brackets in stack
                postfix += s.top_element();
                s.pop();
            }
            if(s.top_element()=='(')
            {
                s.pop();
            }
        }
        else if ( is_operator(infix[i]) )
        {
            //if character is an operator...
            if(s.is_empty())
            {
                //if stack is empty, directly push operator in stack
                s.push(infix[i]);
            }
            else
            {
                if( precedence(infix[i]) > precedence(s.top_element()) )
                {
                    /*if precedence of incoming operator is higher than top
                    element, directly push into stack*/
                    s.push(infix[i]);
                }
                
                else
                {
                    while (!s.is_empty() && (precedence(infix[i]) <= precedence(s.top_element())))
                    {
                        /*pop the top element if precedence of incoming operator
                        is lower than or equal to top element*/
                        postfix += s.top_element();
                        s.pop();
                    }
                    //push incoming operator after popping 
                    s.push(infix[i]);
                }      
            }
        }
    }
    while(!s.is_empty())
    {
        //pop all remaining elements in stack 
        postfix += s.top_element();
        s.pop();
    }
    return postfix;
}

int main()
{
    string infix_str, postfix_str;
    cout << "Enter infix expression: ";
    getline(cin,infix_str);
    Stack st;
    cout << endl << "Infix expression: " << infix_str <<endl;
    postfix_str = infix_to_postfix(st,infix_str);
    cout << endl << "Postfix expression: " << postfix_str;

    return 0;
}
