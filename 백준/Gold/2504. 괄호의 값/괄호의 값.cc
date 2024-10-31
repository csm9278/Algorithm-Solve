#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main()
{
    int answer = 0;
    string s;
    cin >> s;
    stack<char> st;

    int dCount = 1;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            dCount *= 2;
            st.push(s[i]);
        }
        else if(s[i] == '[')
        {
            dCount *= 3;
            st.push(s[i]);
        }
        else if(s[i] == ')')
        {
            if(st.empty() || st.top() != '(')
            {
                answer = 0;
                break;
            }

            if(s[i - 1] == '(')
                answer += dCount;
                
            st.pop();
            dCount /= 2;
        }
        else if(s[i] == ']')
        {
            if(st.empty() || st.top() != '[')
            {
                answer = 0;
                break;
            }

            if(s[i - 1] == '[')
                answer += dCount;

            st.pop();
            dCount /= 3;
        }
    }


    if(!st.empty())
        cout << 0 << endl;
    else
        cout << answer << endl;

    return 0;
}