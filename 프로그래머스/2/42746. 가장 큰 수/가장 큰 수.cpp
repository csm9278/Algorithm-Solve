#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(string a, string b)
{
    return a+ b > b + a;
}


string solution(vector<int> numbers) 
{
    string answer = "";
    vector<string> stVec;
    
    for(auto num : numbers)
    {
        stVec.push_back(to_string(num));
    }
    
    sort(stVec.begin(), stVec.end(), cmp);

    if(stoi(stVec[0]) == 0)
        return "0";
    
    for(auto st : stVec)
        answer += st;
    
    
    return answer;
}