#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool isCon[1000001] = {false};

int solution(vector<int> order) 
{
    int answer = 0;
    int orderIdx = 0;
    stack<int> st;
    
    for(int i = 1 ; i <= order.size(); i++)
    {
        if(isCon[order[orderIdx]])//박스가 보조 컨베이어
        {
            if(st.top() == order[orderIdx])    //맨앞쪽에 있을경우
            {
                answer++;
                isCon[order[orderIdx]] = false;
                st.pop();
                orderIdx++;
                i--;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(i == order[orderIdx])   //현재 순서 맞는지 비교
            {
                answer++;
                orderIdx++;
            }
            else
            {
                st.push(i);
                isCon[i] = true;
            }
        }
    }

    while(!st.empty())
    {
        if(st.top() == order[orderIdx])    //맨앞쪽에 있을경우
        {
            answer++;
            st.pop();
            orderIdx++;
            if(st.empty())
                break;
        }
        else
        {
            break;
        }
    }
    
    return answer;
}