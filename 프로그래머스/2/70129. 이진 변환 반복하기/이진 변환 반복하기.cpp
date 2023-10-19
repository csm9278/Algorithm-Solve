#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string TenToTwo(int num)
{
    string s = "";
    while(num != 0)
    {
        s += to_string(num % 2);
        
        num /= 2;
    }
   
    reverse(s.begin(), s.end());
    return s;
}

vector<int> solution(string s) 
{
    vector<int> answer;
    
    string curst = s;
    string tempst = "";
    int delNum = 0;
    int count = 0;
    
    
    while(curst.size() != 1)
    {
        tempst = "";
        
        for(int i = 0 ; i < curst.size(); i++)
        {
            if(curst[i] == '0')
            {
                delNum++;
            }
            else
            {
                tempst += curst[i];
            }
        }
        
        curst = TenToTwo(tempst.size());
        count++;
    }
    
    answer.push_back(count);
    answer.push_back(delNum);
    
    return answer;
}