#include<iostream>
using namespace std;
class Publication{
	public:
		string title;
		float price;
		
		Publication(){
			title = "";   //Initialising title and price to 0
			price = 0.0;
		}
};//Enf of Publication class

class Book : public Publication{
	public:
		int page_count;
		
		Book(){
			page_count = 0; //Initialising page count to 0
		}
		
		void get_data(){
			cout<<"Enter title of book: "<<endl;
			cin.ignore();
			getline(cin, title);
			cout<<"Enter price of book: "<<endl;
			cin>>price;
			cout<<"Enter page count of book: "<<endl;
			cin>>page_count;
			try{
				if(page_count <= 0 || price <=0){
					throw page_count, price;
				}
			}
			catch(...){              // Replacing all values to 0 if exception is caught
				cout<<"Invalid data entered!"<<endl;
				price = 0;
				page_count = 0;
			}
		}
		
		void display(){
			cout<<"Title of book : "<<title<<endl;
			cout<<"Price of book : "<<price<<" Rupees"<<endl;
			cout<<"Page count : "<<page_count<<" pages"<<endl;
		}
};//End of Book class

class Tape : public Publication{
	public:
		float play_time;
		
		Tape(){
			play_time = 0.0; //Initialising play time to 0.0 minutes
		}
		
		void get_data(){
			cout<<"Enter title of tape: " <<endl;
			cin.ignore();
			getline(cin, title);
			cout<<"Enter price of tape: "<<endl;
			cin>>price;
			cout<<"Enter playing time of tape (minutes) : "<<endl;
			cin>>play_time;
			try{
				if(play_time <= 0 || price <=0){
					throw play_time, price;
				}
			}
			catch(...){             // Replacing all values to 0 if exception is caught
				cout<<"Invalid data entered!"<<endl;
				price = 0;
				play_time = 0;
			}
		}
		
		void display(){
			cout<<"Title of tape : "<<title<<endl;
			cout<<"Price of tape : "<<price<<" Rupees"<<endl;
			cout<<"Playing time of tape : "<<play_time<<" minutes"<<endl;
		}
};//End of Tape class
int main(){
	int ch=0, i=0, j=0;
	Book book_arr[10]; //Object arrays to store multiple objects
	Tape tape_arr[10];
	do{
		cout<<"Menu:"<<"\n"<<"1 = Enter new book"<<"\n"<<"2 = Enter new Tape"<<"\n"<<"3 = Display data"<<"\n"<<"4 = Exit"<<endl;	
		cin>>ch;
		switch(ch){
			case 1:
				book_arr[i].get_data(); //Taking input for "i"th object in array
				i++;
				break;
			case 2:
				tape_arr[j].get_data();
				j++;
				break;
			case 3:
				cout<<"-------**BOOK DATA**-------"<<endl;
				for(int k=0; k<i; k++){
					book_arr[k].display();
					cout<<"---------------------------"<<endl;
				}
				cout<<"-------**TAPE DATA**-------"<<endl;
				for(int l=0; l<j; l++){
					tape_arr[l].display();
					cout<<"---------------------------"<<endl;
				}			
				break;
			case 4:
				exit(0);
		} //End of switch statement
	}while(ch!=4);
	return 0;
}

