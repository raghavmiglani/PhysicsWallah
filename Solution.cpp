/*

Approach: Just take the inputs until we get input as "fin"
set the class limit after taking the init input and dividing it into 4 classes

now just take all the queries as input and make a map which contains 
vectors as value and type of class as a key 

get the class type by adding the class and food types 
Now, push the roll no. of all the students to the particular vector in map according to the key
which we got using the type of food and class

finally print all the classes


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    map<string, vector<int>> class_type;
    unordered_map<int, int> checked;
    class_type["NA"]; class_type["AV"]; class_type["ANV"]; class_type["BV"]; class_type["BNV"];
    int limit = 0;

    while(getline(cin, s))
    {
        if(s == "fin" || s == "")
            break;

        stringstream input(s);  
        // We are using stringstream for converting the whole line of string into partitions
        // according to the spaces and pushing the strings into a vector<string> and solving 
        // further accordingly
        string temp;
        vector<string> v;

        while(input >> temp)
            v.push_back(temp);
        
        if(v[0] == "init")
        {
            int sz = stoi(v[1]);
            limit = sz / 4;
            continue;
        }
        string type = v[2] + v[3];

        int roll = stoi(v[1]); //stoi converting string to integer
        if(checked[roll] == 1)
            continue;
        checked[roll] = 1;

        int sz = class_type[type].size();
        if(sz < limit)
            class_type[type].push_back(roll);
        else
            class_type["NA"].push_back(roll);
    }


    /*Printing all the classes accordingly*/
    for(auto [type, students] : class_type)
    {
        cout << type << " : [";
        int n = students.size();
        for(int i = 0; i < n; i++)
        {
            cout << students[i];
            if(i < n - 1)
                cout << ",";
        }
        cout <<"]\n";
    }
}

/*

Testcase 1 

Input 

init 12
reg 1 B V
reg 2 A V 
reg 3 A V 
reg 4 B NV 
reg 5 B V 
reg 6 A NV 
reg 7 A V 
reg 8 A NV 
reg 9 B NV 
reg 10 B V 
reg 11 A NV 
reg 11 A NV
reg 12 B NV 
reg 13 A NV 
fin


Expected Output:

ANV : [6,8,11] 
AV : [2,3,7]
BNV : [4,9,12] 
BV : [1,5,10]
NA : [13]

Received Output:

ANV : [6,8,11]
AV : [2,3,7]
BNV : [4,9,12]
BV : [1,5,10]
NA : [13]

*/