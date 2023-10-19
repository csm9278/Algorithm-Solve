#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) 
{
    string answer = "";

    vector<int> intVec;
    string t = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            intVec.push_back(stoi(t));
            t = "";
            continue;
        }
        else
        {
            string str = s.substr(i, 1);

            t += str;
            cout << t << endl;

        }
    }
    intVec.push_back(stoi(t));
    

    sort(intVec.begin(), intVec.end());

    answer = to_string(intVec[0]) + ' ' + to_string(intVec[intVec.size() - 1]);
    
    return answer;
}