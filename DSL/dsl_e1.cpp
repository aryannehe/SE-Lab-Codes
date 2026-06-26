/*
DSL Group E Assignment 1
Neeti Kurulkar
SE A 21038

Queues are frequently used in computer programming and a typical example is the 
creation of a job queue by an operating system. If the operating system does not use 
priorities, then the jobs are processed in the order they enter the system. Write C++ 
program for simulating job queue. Write functions to add job and delete job from queue. 
*/

#include<iostream>
using namespace std;

//create queue
class Queue
{
    public:
        const static int size=10;  //set size of queue to 10
        int rear=-1;
        int front=-1;
        int queue[size];

        //add to queue
        void enqueue(int x)
        {
            if(rear==size-1) //full queue condition
            {
                cout<<"Queue is Full.";
            }
            else if(front==-1 && rear==-1) //empty queue condition
            {
                front=rear=0;
                queue[rear]=x;
            }
            else
            { 
                rear++;
                queue[rear]=x;
            }
        }

        //remove from queue
        void dequeue()
        {
            if(front==-1 && rear==-1) //empty queue condition
            {
                cout << "Queue is Empty." << endl;
                
            }
                
            else if(front == rear) //single element condition
                {
                    front = rear = -1;
                }

            else
                {
                    cout << queue[front] << endl;
                    front = (front+1)%size;
                    
                }
            
        
        }

        //display queue
        void display()
        {   
            if (front==-1 && rear==-1) //empty queue ondition
            {
                cout << "Queue is Empty." << endl;
            }
            else
            { 
                cout<<"Queue Contains:";
                for(int i=front; i<=rear; i++) //traverse through entire queue
                {
                    cout << queue[i] << " ";
                }
                cout<<endl;
            }
        }
    
};

int main()
{
    Queue job_line;
    int choice,val;

    do{
        cout<<"Menu: "<< endl;
        cout<<"1 = Add Job" << endl;
        cout<<"2 = Delete Job " << endl;
        cout<<"3 = Display Queue" << endl;
        cout<<"4 = Exit" << endl;
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                cout<<"Enter Job:"<<endl;
                cin>>val;
                job_line.enqueue(val);
                break;

            case 2:
                cout<<"Deleting job...";
                job_line.dequeue();
                break;

            case 3:
                job_line.display();
                break;

            case 4:
                exit(0);
                break;

            default:
                cout<<"Invalid input.";
                break;
        }
    }while(choice!=4);
    return 0;
}