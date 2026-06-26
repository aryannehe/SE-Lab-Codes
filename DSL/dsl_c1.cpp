/*
DSL Group C Assignment 1
Neeti Kurulkar
SE A 21038

The ticket booking system of Cinemax theater has to be implemented using C++ program. 
There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained 
to keep track of free seats at rows. Assume some random booking to start with. Use array to 
store pointers (Head pointer) to each row On demand

A. The list of available seats is to be displayed
B. The seats are to be booked
C. The booking can be cancelled
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class Node 
{
    public:
        Node* next;
        Node* prev;
        int seat_no, status;
        string id;
};

class Cinema
{
    public:
        Node* head,* tail,* temp;
    Cinema()
    {
        head = NULL;
    }
    void create_list();
	void display();
	void book();
	void cancel();
};

void Cinema::create_list()
{
    int i = 1;
    temp = new Node; //creating temporary node
    temp->seat_no = 1;  //initialising values for temporary node
    temp->status = 0;
    temp->id = "null";
    tail = head = temp; //initial position of all pointers
    for(i = 2; i <= 70; i++)
    {
        Node* ptr;
        ptr = new Node;
        ptr->seat_no=i; //initialising values for ptr node
		ptr->status=0;
		ptr->id="null";

		tail->next=ptr; //inserting ptr at tail
		ptr->prev=tail;

		tail=ptr; //now ptr becomes tail

		tail->next=head; //connecting tail to head
		head->prev=tail;
    }
}

void Cinema::display()
{
	int row = 1, count = 0;
	Node* temp;
	temp = head;
	cout << "\n-----------------------------------------------------------------------------------\n";
	cout << " Screen this way \n";
	cout << "-------------------------------------------------------------------------------------\n";
	while(temp->next != head) //displays first 69 seats beacuse 70th seat has next = NULL
	{
		if(temp->seat_no/10==0) //if seat number is less than 10
			cout<<"S0"<<temp->seat_no<<" :";
		else
			cout<<"S"<<temp->seat_no<<" :";

		if(temp->status==0) //displaying if seat is booked or not
			cout<<"|___| ";
		else
			cout<<"|_B_| ";

		count++;

		if(count%7==0) //display 7 seats in a row
		{
			cout<<endl;
			row++;
		}
		temp=temp->next;
	}
    //displaying last seat (seat number 70)
	cout<<"S"<<temp->seat_no<<" :";
	if(temp->status==0)
		cout<<"|___| ";
	else
		cout<<"|_B_| ";
    cout << endl;
}

void Cinema::book()
{ 
	int x;
	string y;
	cout<<"Enter seat number to be booked: ";
	cin>>x;
	cout<<"Enter your ID number: ";
	cin>>y;
	if((x < 1) || (x > 70))
	{
		cout<<"Enter valid seat number (1-70)." << endl;
	}

	Node *temp;
	temp=new Node;
	temp=head;
	while(temp->seat_no != x) //traverse until desired seat number
	{
		temp=temp->next;
	}

	if(temp->status == 1)
		cout<<"Seat already booked!\n";
	else
	{
		temp->status = 1;
		temp->id = y;
		cout << "Seat " << x << " booked." << endl;
	}
}

void Cinema::cancel()
{
    int x;
	string y;
	cout<<"Enter seat number to be cancelled: ";
	cin>>x;
	cout<<"Enter your ID number: ";
	cin>>y;
	if((x < 1) || (x > 70))
	{
		cout<<"Enter valid seat number (1-70)." << endl;
	}

    Node *temp;
	temp=new Node;
	temp=head;
	while(temp->seat_no != x) //traverse until desired seat number
	{
		temp=temp->next;
	}
     
    if (temp->status == 0)
    {
        cout << "Seat is empty." << endl;
    }
    else
    {
        if (y == temp->id)
        {
            temp->status = 0;
            cout << "Seat number " << temp->seat_no << " has been cancelled." << endl;
        }
        else
        {
            cout << "Seat number and ID no not match. Cannot cancel seat. " << endl;
        }
    }

}

int main()
{ 
	Cinema seat_list;
	seat_list.create_list();
	int op;
    do
    {
        cout << "-----------------------------------MOVIE THEATER-----------------------------------" << endl;
        cout << "Menu: " << endl;
        cout << "1 = Show Seats" << endl;
        cout << "2 = Book seat" << endl;
        cout << "3 = Cancel seat" << endl;
        cout << "4 = Exit" << endl;

        cin >> op;

        switch(op)
        {
            case 1:
                seat_list.display();
			    break;

			case 2: 
                seat_list.book();
			    break;
			case 3: 
                seat_list.cancel();
			    break;
            case 4:
                exit(0);
                break;

			default: 
                cout << "Invalid input" << endl;
        }
    }while (op != 4);
	return 0;
}
