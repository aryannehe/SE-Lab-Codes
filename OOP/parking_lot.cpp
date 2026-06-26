#include <iostream>
#include <stdlib.h>
using namespace std;

class Node 
{
    public:
        Node* next;
        Node* prev;
        int slot_no, status;
        string id;
};

class ParkingLot
{
    public:
        Node* head,* tail,* temp;
    ParkingLot()
    {
        head = NULL;
    }
    void create_list();
	void display();
	void book();
	void cancel();
};

void ParkingLot::create_list()
{
    int i = 1;
    temp = new Node; //creating temporary node
    temp->slot_no = 1;  //initialising values for temporary node
    temp->status = 0;
    temp->id = "null";
    tail = head = temp; //initial position of all pointers
    for(i = 2; i <= 50; i++)
    {
        Node* ptr;
        ptr = new Node;
        ptr->slot_no=i; //initialising values for p node
		ptr->status=0;
		ptr->id="null";

		tail->next=ptr; //inserting p at tail
		ptr->prev=tail;

		tail=ptr; //now p becomes tail

		tail->next=head; //connecting tail to head
		head->prev=tail;
    }
}

void ParkingLot::display()
{
	int row = 1, count = 0;
	Node* temp;
	temp = head;
	cout << "\n-----------------------------------------------------------------------------------\n";
	cout << " Entry this way \n";
	cout << "-------------------------------------------------------------------------------------\n";
	while(temp->next != head) //displays first 49 slots beacuse 70th slot has next = NULL
	{
		if(temp->slot_no/10==0) //if slot number is less than 10
			cout<<"P0"<<temp->slot_no<<" :";
		else
			cout<<"P"<<temp->slot_no<<" :";

		if(temp->status==0) //displaying if slot is booked or not
			cout<<"|___| ";
		else
			cout<<"|_P_| ";

		count++;

		if(count%10==0) //display 10 slots in a row
		{
			cout<<endl;
			row++;
		}
		temp=temp->next;
	}
    //displaying last seat (seat number 70)
	cout<<"P"<<temp->slot_no<<" :";
	if(temp->status==0)
		cout<<"|___| ";
	else
		cout<<"|_P_| ";
    cout << endl;
}

void ParkingLot::book()
{ 
	int x;
	string y;
	cout<<"Enter parking slot number to be booked: ";
	cin>>x;
	cout<<"Enter your ID number: ";
	cin>>y;
	if((x < 1) || (x > 50))
	{
		cout<<"Enter valid slot number (1-50)." << endl;
	}

	Node *temp;
	temp=new Node;
	temp=head;
	while(temp->slot_no != x) //traverse until desired seat number
	{
		temp=temp->next;
	}

	if(temp->status == 1)
		cout<<"Slot already booked!\n";
	else
	{
		temp->status = 1;
		temp->id = y;
		cout << "Slot " << x << " booked." << endl;
	}
}

void ParkingLot::cancel()
{
    int x;
	string y;
	cout<<"Enter seat number to be cancelled: ";
	cin>>x;
	cout<<"Enter your ID number: ";
	cin>>y;
	if((x < 1) || (x > 50))
	{
		cout<<"Enter valid slot number (1-50)." << endl;
	}

    Node *temp;
	temp=new Node;
	temp=head;
	while(temp->slot_no != x) //traverse until desired seat number
	{
		temp=temp->next;
	}
     
    if (temp->status == 0)
    {
        cout << "Slot is empty." << endl;
    }
    else
    {
        if (y == temp->id)
        {
            temp->status = 0;
            cout << "Slot number " << temp->slot_no << " has been cancelled." << endl;
        }
        else
        {
            cout << "Slot number and ID no not match. Cannot cancel slot. " << endl;
        }
    }

}

int main()
{ 
	ParkingLot car_list;
	car_list.create_list();
	int op;
    do
    {
        cout << "-----------------------------------PARKING LOT-----------------------------------" << endl;
        cout << "Menu: " << endl;
        cout << "1 = Show Slots" << endl;
        cout << "2 = Book slot" << endl;
        cout << "3 = Cancel slot" << endl;
        cout << "4 = Exit" << endl;

        cin >> op;

        switch(op)
        {
            case 1:
                car_list.display();
			    break;

			case 2: 
                car_list.book();
			    break;
			case 3: 
                car_list.cancel();
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
