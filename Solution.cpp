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
    map<string, vector<int>> mp;
    unordered_map<int, int> checked;
    mp["NA"]; mp["AV"]; mp["ANV"]; mp["BV"]; mp["BNV"];
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

        int sz = mp[type].size();
        if(sz < limit)
            mp[type].push_back(roll);
        else
            mp["NA"].push_back(roll);
    }


    /*Printing all the classes accordingly*/
    for(auto [type, students] : mp)
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
