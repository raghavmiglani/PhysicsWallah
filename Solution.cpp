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

        int roll = stoi(v[1]);
        if(checked[roll] == 1)
            continue;
        checked[roll] = 1;

        int sz = mp[type].size();
        if(sz < limit)
            mp[type].push_back(roll);
        else
            mp["NA"].push_back(roll);
    }

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
