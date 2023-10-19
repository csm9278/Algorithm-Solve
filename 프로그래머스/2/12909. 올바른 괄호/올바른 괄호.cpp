#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    if(s[0] == ')' || s[s.size() - 1] == '(')
        return false;
    
    int count = 0;
    for(int i = 0 ; i < s.size(); i++)
    {
        if(s[i] == '(')
            count++;
        else if(s[i] == ')')
            count--;
        
        if(count < 0)
            return false;
    }
    
    if(count != 0)
        return false;
    
    return answer;
}