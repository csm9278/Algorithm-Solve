#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void order(vector<int>* vec, string s)
{
    if(s[0] == 'I')
    {
        string num = "";
        for(int i = 2; i < s.size(); i++)
        {
            num += s[i];
        }
        vec->push_back(stoi(num));
    }
    else if(s[0] == 'D')
    {
        if(vec->size() <= 0)
            return;
        
        sort(vec->begin(), vec->end()); 
        if(s[2] == '1')
        {
            vec->erase(vec->end()-1);
        }
        else
            vec->erase(vec->begin());
    }
}

vector<int> solution(vector<string> operations) 
{
    vector<int> odvec;
    vector<int> answer;
    
    for(int i = 0; i < operations.size(); i++)
    {
        order(&odvec, operations[i]);
    }
    
    if(odvec.size() <= 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        sort(odvec.begin(), odvec.end());
        answer.push_back(odvec[odvec.size() - 1]);
        answer.push_back(odvec[0]);
    }
    
    return answer;
}