#include<iostream>
using namespace std;
class Complex
{
	private:
		int r, i; 
	public:
	    //Constructor to initialize value to 0
		Complex()
		{
			r = i = 0;
		}
		
		void show_add()
		{
			cout<<"Addition is: "<<r<<"+"<<i<<"i"<<endl;
		}
		
		void show_mul()
		{
			cout<<"Multiplication is: "<<r<<"+"<<i<<"i"<<endl;
		}
		
		//Overloading the addition(+) operator
		Complex operator +(Complex c1)
		{
			Complex c2;
			c2.r = r + c1.r;
			c2.i = i + c1.i;
			return c2;
		}
		
		//Overloading the multiplication(*) operator
		Complex operator *(Complex c1)
		{
			Complex c2;
			c2.r  = c1.r*r - c1.i*i;
			c2.i = c1.r*i + c1.i*r;
			return c2;
		}
		
		//Overloading the extraction operator
		friend ostream& operator <<(ostream& output, Complex& obj)
		{
			output<<obj.r<< "+"<<obj.i<<"i";
			return output;
		}
		
		//overloading the insertion operator
		friend istream& operator >>(istream& input, Complex& obj)
		{
			input>>obj.r>>obj.i;
			return input;
		}
};
int main()
{
	Complex d, e, add, mul;
	cout<<"Enter first number: "<<endl;
	cin>>d;
	cout<<"Enter second number: "<<endl;
	cin>>e;
	cout<<d<<endl<<e<<endl;
	add = d + e;
	mul = d*e;
	add.show_add();
	mul.show_mul();
	return 0;
}
