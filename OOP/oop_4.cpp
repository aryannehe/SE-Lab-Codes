#include <iostream>
#include <fstream>
using namespace std;
class Student
{
    private:
        string name;
        int roll_no;
    public:
        //function to add info to file
        void add_info()
        {
            fstream fs;  //creating object of fstream class

            fs.open("sample.txt", ios :: app);  // opening file in append mode

            if(!fs)
            {
                cout << "File creation failed." << endl;
            }
            else
            {
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter roll number: ";
                cin >> roll_no;

                //writing into file
                fs << name << " ";
                fs << roll_no << endl;
                fs.close(); // closing file
            }

        }

        //function to display info from file
        void display()
        {
            fstream fs; //creating object of fstream class

            fs.open("sample.txt", ios :: in);  //opening file in read mode

            if(!fs)
            {
                cout << "File doesn't exist." << endl;
            }
            else
            {
                cout << "------------**Information**------------" << endl;
                while (!fs.eof())
                {
                    fs >> name;
                    fs >> roll_no;

                    if (!fs.eof())
                    {
                        cout << name << " ";
                        cout << roll_no << endl;                        
                    }
                }
                cout << "---------------------------------------" << endl;
            }
        }
};  //end of Student class

int main()
{
    int ch;
    Student s;
    fstream fs;
    do
    {
        cout << "---------------**MENU**---------------" << endl;
        cout << "1 = Add Information. " << endl;
        cout << "2 = Display Information. " << endl;
        cout << "3 = Exit. " << endl;
        cout << "--------------------------------------" << endl;
        cin >> ch;

        //calling respective function based on user's choice
        switch(ch)
        {
            case 1:
                s.add_info();
                break;
            case 2:
                s.display();
                break;
            case 3:
                exit(0);
                break;
        }
    } while (ch != 3);
    return 0;    
}