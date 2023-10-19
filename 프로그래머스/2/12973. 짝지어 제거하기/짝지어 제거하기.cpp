#include <iostream>
#include <stack>
#include<string>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> st;
    for(auto& c : s)
    {
        if(!st.empty())
        {
            if(st.top() == c)
                st.pop();
            else
                st.push(c);
        }
        else
            st.push(c);
    }
    
    
    
    return st.empty() ? 1 : 0;
}