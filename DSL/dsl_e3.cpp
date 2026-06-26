/*
DSL Group E Assignment 3
Neeti Kurulkar
SE A 21038

Write program to implement a priority queue in C++ using an inorder list to store the items 
in the queue. Create a class that includes the data items (which should be template) and the 
priority (which should be int). The inorder list should contain these objects, with operator 
<= overloaded so that the items with highest priority appear at the start of the list (which 
will make it relatively easy to retrieve the highest item.)
*/

#include<iostream>
using namespace std;

const int N = 10; //set size of queue to 10

//create priority queue
class PriorityQ
{
    int front = -1;
    int rear = -1;
    int element[N]; //array to store queue elements
    int priority[N]; //array to store prorities
  
    public:
        
        //add to queue
        void enqueue(int ele, int pr)
        {
            if(rear==N-1) //full queue condition
            {
                cout<<"Queue is Full!"<<endl;
                return;
            }
            else if(front==-1 && rear==-1) //empty queue condition
            {
                front = rear = 0;
                element[rear] = ele;
                priority[rear] = pr;
            }
            else
            {
                int i;
                for(i=rear; i>=front; i--) //traverse through entire queue from right
                {
                    if(pr>=priority[i]) //check priority
                    {
                        //lower priority elements placed later
                        element[i+1] = element[i];
                        priority[i+1] = priority[i];
                    }
                    else
                    {
                        break;
                    }
                }
                element[i+1] = ele;
                priority[i+1] = pr;
                rear++;
                cout << "Element added." << endl;
            }
        }

        //remove from queue
        void dequeue()
        {
            int temp, temp1;
            if(front==-1 && rear==-1) //empty queue condition
            {
                cout << "Queue is Empty." << endl;
                return;
            }
            else if(front==rear) //single element condition
            {
                temp = element[front];
                temp1 = priority[front];
                front = rear = -1;
            }
            else
            {
                temp = element[front];
                temp1 = priority[front];
                front++;
            }
            cout<<"Element:" << temp << " with priority " << temp1 << " removed." << endl;
        }

        //display queue
        void display()
        {
            if(front==-1 && rear==-1) //empty queue condtion
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                cout<<"Element , Priority:"<<endl;
                for(int i=front;i<=rear;i++) //traverse from left to right
                {
                    cout << element[i] << "," << priority[i] << endl;
                }
            }
        }
    
};

int main()
{
    PriorityQ queue;
    int ch;
    int ele, pr;
    do
    {
        cout << "Menu: "<<endl;
        cout << "1 = Add element"<<endl;
        cout << "2 = Remove element"<<endl;
        cout << "3 = Display"<<endl;
        cout << "4 = Exit." << endl;

        cin >> ch;
        switch(ch)
        {
            case 1:
                cout << "Enter Element:"<<endl;
                cin >> ele;
                cout << "Enter Priority (1 < 2 < 3): "<<endl;
                cin >> pr;
                queue.enqueue(ele,pr);
                break;

            case 2:

                queue.dequeue();
                break;

            case 3:
                queue.display();
                break;

            case 4:
                exit(0);
                break;

            default:
                cout << "Invalid input" << endl;
                break;
        }
    }while(ch!=4);
    return 0;
}


/*
    #include<iostream>
using namespace std;

const int N = 10; //set size of queue to 10

//create priority queue
template <class T>
class PriorityQ
{
    int front = -1;
    int rear = -1;
    T element[N]; //array to store queue elements
    int priority[N]; //array to store prorities
  
    public:
        
        //add to queue
        void enqueue(T ele, int pr)
        {
            if(rear==N-1) //full queue condition
            {
                cout<<"Queue is Full!"<<endl;
                return;
            }
            else if(front==-1 && rear==-1) //empty queue condition
            {
                front = rear = 0;
                element[rear] = ele;
                priority[rear] = pr;
            }
            else
            {
                int i;
                for(i=rear; i>=front; i--) //traverse through entire queue from right
                {
                    if(pr>=priority[i]) //check priority
                    {
                        //lower priority elements placed later
                        element[i+1] = element[i];
                        priority[i+1] = priority[i];
                    }
                    else
                    {
                        break;
                    }
                }
                element[i+1] = ele;
                priority[i+1] = pr;
                rear++;
                cout << "Element added." << endl;
            }
        }

        //remove from queue
        void dequeue()
        {
            int temp, temp1;
            if(front==-1 && rear==-1) //empty queue condition
            {
                cout << "Queue is Empty." << endl;
                return;
            }
            else if(front==rear) //single element condition
            {
                temp = element[front];
                temp1 = priority[front];
                front = rear = -1;
            }
            else
            {
                temp = element[front];
                temp1 = priority[front];
                front++;
            }
            cout<<"Element:" << temp << " with priority " << temp1 << " removed." << endl;
        }

        //display queue
        void display()
        {
            if(front==-1 && rear==-1) //empty queue condtion
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                cout<<"Element , Priority:"<<endl;
                for(int i=front;i<=rear;i++) //traverse from left to right
                {
                    cout << element[i] << "," << priority[i] << endl;
                }
            }
        }
    
};

int main()
{
    PriorityQ<int> queue;
    int ch;
    int ele, pr;
    do
    {
        cout << "Menu: "<<endl;
        cout << "1 = Add element"<<endl;
        cout << "2 = Remove element"<<endl;
        cout << "3 = Display"<<endl;
        cout << "4 = Exit." << endl;

        cin >> ch;
        switch(ch)
        {
            case 1:
                cout << "Enter Element:"<<endl;
                cin >> ele;
                cout << "Enter Priority (1 < 2 < 3): "<<endl;
                cin >> pr;
                queue.enqueue(ele,pr);
                break;

            case 2:

                queue.dequeue();
                break;

            case 3:
                queue.display();
                break;

            case 4:
                exit(0);
                break;

            default:
                cout << "Invalid input" << endl;
                break;
        }
    }while(ch!=4);
    return 0;
}
*/