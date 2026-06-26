/*
DSL Group E Assignment 2
Neeti Kurulkar
SE A 21038

Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. 
Order once placed cannot be cancelled. Write C++ program to simulate the system using circular 
queue using array. 
*/

#include<iostream>
using namespace std;

//create queue
class Queue
{
    public:
        const static int size=5;    //set size of queue to 5
        int rear=-1;
        int front=-1;
        int queue[size];

        //enqueue operation
        void place_order(int x)
        {
            if(front==-1 && rear==-1) //empty queue condition
            {
                front = rear = 0;
                queue[rear] = x;
            }
            else if(((rear+1) % size) == front) //full queue condition
            {
                cout << "Sorry, You Can't order. Maximum order limit reached." << endl;
            }
            else
            {
                rear=(rear+1)%size;
                queue[rear] = x;
            }
        }

        //dequeue operation
        void deliver_order()
        {
            if(front==-1 && rear==-1) //empty queue condition
            {
                cout<<"All Pizzas Delivered." << endl;
            }
            else if(front == rear) //single element condition
            {
                front = rear = -1;
            }
            else
            {
                cout << "Delivered Pizza:" << queue[front];
                front= (front+1) % size;
            }
        }

        //display queue
        void display()
        {
            int i = front;
            if(front==-1 && rear==-1) //empty queue condition
            {
                cout << "All Pizzas Delivered." << endl;
            }
            else
            {
                
                while(i != rear) //traverse through entire queue
                {
                    cout << "The ordered Pizza's are:" << queue[i] << endl;
                    i = (i+1) % size;
                }
                cout << "The ordered Pizza's are:" << queue[rear];
            }
        }
};
int main()
{
    Queue q;
    int val, choice;
     do{
        cout << "Menu: " << endl;
        cout << "1 = Place an Order" << endl;
        cout << "2 = Display Order" << endl;
        cout << "3 = Deliver Order" << endl;
        cout << "4 = Exit" << endl;
        
        cin >> choice;

        switch(choice)
        {
            case 0:
                break;

            case 1:
                int val;
                cout << "Pizza types: 1 = Veg 2 = Chicken 3 = Cheese" << endl;
                cout << "Enter pizza type number:" << endl;
                cin >> val;
                if(val>3)
                {
                    cout << "Invalid input." << endl;
                }
                else
                {
                    cout << "Order Placed for Pizza type: " << val << endl;
                    q.place_order(val); //add to queue
                }
                break;

            case 2:
                q.display();
                break;

            case 3:
                q.deliver_order();            
                break;

            case 4:
                exit(0);
                break;

            default:
                cout<<"Invalid input"<<endl;
        }
    }while(choice!=4);      
        
    return 0;
}