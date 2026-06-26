/*
DSL Group D Assignment 2
Neeti Kurulkar
SE A 21038

In any language program mostly syntax error occurs due to unbalancing delimiter such 
as (), {}, []. Write C++ program using stack to check whether given expression is well 
parenthesized or not. 
*/


#include<iostream>
using namespace std;
const int MAX=20;

//create stack
class Stack
{
	char str[MAX];
	int top;
	public:
		Stack()
		{
			top=-1;
		}
		void push(char ch);
		char pop();
	//	char getTop();
		bool is_empty();
		bool is_full();
		void display();
		void check_parenthesis();
};

//check if stack is empty
bool Stack::is_empty()
{
	if(top==-1)
		return 1;
	else return 0;
}

//check if stack is full
bool Stack::is_full()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}

//display stack
void Stack :: display()
{
	if(is_empty()==1)
    {
        cout << "Stack is empty" << endl;
    }
	else
	{
		for(int i=0;i<=top;i++)
		{
			cout << " " << str[i];
		}
        cout << endl;
	}
}

//push into stack
void Stack::push(char ch)
{
    if (is_full())
    {
        cout << "Stack is full! " << endl;
    }
	else
	{
		top++;
		str[top]=ch;
	}

}


//pop from stack
char Stack::pop()
{
    if (is_empty())
    {
        cout << "Stack is empty!" << endl;
    }
	else
	{
		char ch=str[top];
		top--;
		return ch;
	}
}

void Stack::check_parenthesis()
{
	cout<<"\nEnter # as a deliminator after expression(At the end)\n";
	cout<<"\nEnter Expression: ";
	cin.getline(str,MAX,'#');
	char ch;
	bool flag=0;
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='(' || str[i]=='[' || str[i]=='{')
            //pushing opening brackets into stack
			push(str[i]);
		if(str[i]==')'||str[i]==']'||str[i]=='}')
		{
            //popping opening brackets from stack when closing bracket is encountered
			ch=pop();
			if((str[i]==')'&& ch!='(') ||(str[i]==']'&& ch!='[')||(str[i]=='}'&& ch!='{'))
			{
                //finding which bracket is not well parenthesized
				cout << "Not parenthesized At " << i << " = " << str[i] << endl;
				flag=1;
				break;
			}
		}
	}
	if(is_empty()==1 && flag==0)
		cout << "Expression is Well Parenthesized." << endl;
	else
		cout << "Expression is not Well Parenthesized." << endl;
}

int main()
{

	int choice;
	do
	{
		Stack s;
		s.check_parenthesis();
		cout << "Do you want to continue? 1 = yes 2 = no ";
		cin >> choice;
	}while(choice != 2);

	return 0;
}