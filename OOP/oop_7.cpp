#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    typedef map<string, int> mapType;
    mapType populationMap;  //creates an empty map

    // Inserting respective populations in map
    populationMap.insert(pair<string, long>("Maharashtra", 1231521145));
    populationMap.insert(pair<string, long>("Gujrath", 5331521145));
    populationMap.insert(pair<string, long>("Punjab", 7678552356));
    populationMap.insert(pair<string, long>("Karnataka", 8955955854));
    populationMap.insert(pair<string, long>("Tamilnadu", 564565465));

    //iterator for map
    mapType::iterator i;

    //Display the size of a map
    cout <<"----------------------Population of states in India----------------------" << endl;;
    cout << "Size of populationMap : " << populationMap.size() << endl;

    int ch = 1;
    string state_name;

    while (ch == 1)  //Runs until user says no
    {
        cout << "Enter state name : ";
        cin >> state_name;

        i = populationMap.find(state_name); //will return an iterator to matching element if it is found

        if(i != populationMap.end())
        {
            cout<<state_name<<"'s population is : "<<i -> second << endl;
        }
        else
        {
            cout << state_name << " not present in populationMap" << endl;
        }

        cout << "Do you want to continue? \n 1 = Yes, 2 = No" << endl;
        cin >> ch;
    }

    return 0;
}

