#include <iostream>
using namespace std;
template <class T> // function template

//function for selection sort
void sort(T a[], int n)
{
    int i, j, min_index;
    T temp;
    for (int i = 0; i < n-1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                // changing minimum index if element at jth index is smaller
                min_index = j;
            }
        }
        if (min_index != i)
        {
            //swapping if minimum index changes 
            temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
    cout << "Sorted elements are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main()
{
    int n, i, ch;
    int a[10];
    float b[10];
    do 
    {
        cout << "---------------**MENU**---------------" << endl;
        cout << "Selection Sort using templates: " << endl;
        cout << "1 = Sort Integers." << endl;
        cout << "2 = Sort Floating point numbers." << endl;
        cout << "3 = Exit" << endl;
        cout << "--------------------------------------" << endl;

        cin >> ch;

        //calling function according to user's choice
        switch(ch)
        {
            case 1:
            cout << "Sorting Integers: " << endl;
            cout << "Enter number of integers to sort: " << endl;
            cin >> n;
            cout << "Enter the numbers: " << endl;

            //taking input for integers
            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            
            //calling sort function for integers
            sort<int>(a, n);
            break;

            case 2:
            cout << "Sorting floaring point numbers: " << endl;
            cout << "Enter number of floating point numbers to sort: " << endl;
            cin >> n;
            cout << "Enter the numbers: " << endl;

            //taking input for floating point numbers
            for (int i = 0; i < n; i++)
            {
                cin >> b[i];
            }

            //calling sort function for floating point numbers
            sort<float>(b, n);
            break;

            case 3:
            exit(0);
            break;
        }// end of switch case
    }while(ch != 3);
    return 0;
}
