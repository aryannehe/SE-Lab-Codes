#include <iostream>
using namespace std;
class Student{
    private:
        string name, std, dob, bg, add, tel_no, lic_no;
        int roll_no;
        int divi;
        friend class Faculty;
    public:
        //Constructor to initialize default values to all variables
        Student(string name="n/a", int* roll_no=0, string std="n/a", int divi=0, 
        string dob="n/a", string bg="n/a", string add="n/a", string tell_no="n/a", string lic_no="n/a"){
            this->roll_no = 0;
            this->name=name;
            this->std=std;
            this->divi=divi;
            this->dob=dob;
            this->bg=bg;
            this->add=add;
            this->tel_no=tel_no;
            this->lic_no=tel_no;
        }
        
        //Function to input data
        void get_data(){
            cout<<"Enter student information: "<<endl;
            cout<<"--------------------------------"<<endl;
            cout<<"Enter name of student: "<<endl;
            cin.ignore();
            getline(cin, name);
            cout<<"Enter roll number: "<<endl;
            cin>>roll_no;
            cout<<"Enter class: (FE/SE/TE/BE)"<<endl;
            cin>>std;
            cout<<"Enter division: (1/2/3/4) "<<endl;
            cin>>divi;
            cout<<"Enter date of birth (DD/MM/YYYY): "<<endl;
            cin>>dob;
            cout<<"Enter blood group: "<<endl;
            cin>>bg;
            cout<<"Enter contact address: "<<endl;
            cin.ignore();
            getline(cin, add);
            cout<<"Enter telephone number: "<<endl;
            cin>>tel_no;
            cout<<"Enter licence number: "<<endl;
            cin>>lic_no;
        }
        
        //Function to display data
        void display(){
            cout<<"------STUDENT INFORMATION------"<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Roll number: "<<roll_no<<endl;
            cout<<"Class: "<<std<<endl;
            cout<<"Division: "<<divi<<endl;
            cout<<"Date of birth: "<<dob<<endl;
            cout<<"Blood group: "<<bg<<endl;
            cout<<"Contact address: "<<add<<endl;
            cout<<"Telephone number: "<<tel_no<<endl;
            cout<<"Licence number: "<<lic_no<<endl;
            cout<<"-------------------------------"<<endl;
        }
        
        //static function for header
        static void header(){
            cout<<"*****STUDENT INFORMATION*****"<<endl;
        }
        
        //destructor to delete object
        ~Student(){}
};//End of student class

class Faculty{
    private:
        int id;
    public:
        //Constructor to initialize value to 0
        Faculty(int id=00){
            this->id=id;
        }
        //Copy constructor 
        Faculty(const Faculty &f1){
            id=f1.id;
        }
        void f_display(Student &obj, int f_div){
            try{
                if (obj.divi==f_div)
                obj.display();
                else
                throw(obj.divi);
            }
            catch(int x){
                cout<<"Invalid division entered."<<endl;
            }
        }
    
}; //End of Faculty class

int main(){
    Student* stu_array = new Student[10];
    Faculty f;
    int ch = 0, count = 0;
    do{
        cout<<"-------MENU-------"<<endl;
        cout<<"1 = Enter data: "<<endl;
        cout<<"2 = Display data: "<<endl;
        cout<<"3 = Display faculty data: "<<endl;
        cout<<"4 = Exit"<<endl;
        cout<<"------------------"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                stu_array[count].get_data();
                count++;
                break;
                
            case 2:
            Student::header();
            for (int i = 0; i<count; i++){
                stu_array[i].display();
            }
            break;
            
            case 3:
                int fac_div;
                cout<<"Enter faculty divsion: "<<endl;
                cin>>fac_div;
                for (int j = 0; j<count; j++){
                    f.f_display(stu_array[j], fac_div);
                }
                break;
            
            case 4:
                exit(0);
        }//End of switch
        
    }while(ch!=4);//End of do while loop
    delete [] stu_array;
    return 0;
}//End of main function
