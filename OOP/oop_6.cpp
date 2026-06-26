#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Record
{
    public:
    string name, dob;
    int id, mob_no;

    //overloading == operator
    bool operator == (const Record& r)
    {
        return (id == r.id);
    }

    //overloading < operator
    bool operator < (const Record& r)
    {
        if(id < r.id)
            return 1;
        return 0;
    }

    //overloading >> operator
    friend istream& operator >> (istream &in, Record &r)
    {
        cout << "Enter ID: ";
        cin >> r.id;
        cout << "Enter Name: ";
        cin >> r.name;
        cout << "Enter Mobile Number: ";
        cin >> r.mob_no;
        cout << "Enter Date of Birth: ";
        cin >> r.dob;

        return in;
    }

    //overloading << operator
    friend ostream& operator << (ostream &out, Record &r)
    {
        cout << "--------------------------------------" << endl;
        cout << "ID : " << r.id << endl;
        cout << "Name : " << r.name << endl;
        cout << "Mobile No. : " << r.mob_no << endl;
        cout << "Date of birth : " << r.dob << endl;
        cout << "--------------------------------------" << endl;
    }    
};

vector <Record> rec;

//function to create a new record
void insert()
{
    int n;
    Record r;

    cout << "Enter number of records: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> r;
        rec.push_back(r);  //inserts at end of vector
    }
}

//function for printing object variables
void print(Record &r)
{
    cout << r;
}

//function to display all data
void display()
{
    for_each(rec.begin(), rec.end(), print);
}

//function to search record based on ID
void search()
{
    Record r2;
    cout << "Enter ID to search: ";
    cin>> r2.id;
    vector <Record> :: iterator p;
    p = find(rec.begin(), rec.end(), r2); //iterates from beginning to end of vector
    if (p == rec.end())
    {
        cout << "Record not found. " << endl;
    }
    else
    {
        cout << "Record found. " << endl;
    }
}      

//function to return smaller ID
bool compare (Record &x, const Record &y)
{
    return (x.id < y.id);
}
        
//function to sort records
void sort()
{
    sort(rec.begin(), rec.end(), compare);  //sorts according to compare function
}

//function to delete record
void del()
{
    vector <Record> :: iterator p;  //creates an iterator
    Record r2;
    cout << "Enter ID of record to delete: ";
    cin >> r2.id;
    p = find(rec.begin(), rec.end(), r2);  //searches entire vector
    if (p == rec.end())
    {
        cout << "Record not found. " << endl;
    }
    else
    {
        rec.erase(p);
        cout << "Record deleted." << endl;
    }
}

int main()
{
    int ch;
    
    do 
    {
        cout << "Menu: -------------------------------" << endl;
        cout << "1 = Create record" << endl;
        cout << "2 = Display all records" << endl;
        cout << "3 = Search record" << endl;
        cout << "4 = Sort records " << endl;
        cout << "5 = Delete record" << endl;
        cout << "6 = Quit" << endl;
        cout << "--------------------------------------" << endl;

        cin >> ch;
        
        //calling respective function based on user's choice
        switch(ch)
        {
            case 1:
                insert();
                break;
            
            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                cout << "Sorted according to ID." << endl;
                sort();
                display();
                break;

            case 5:
                del();
                break;

            case 6:
                exit (0);
                break;
        }//end of switch case
    }while(ch != 6);
}
