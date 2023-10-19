#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    int answer = 0;
    queue<pair<int, int>> que;
    priority_queue<int> pque;
    
    for(int i = 0 ; i < priorities.size(); i++)
    {
        que.push(make_pair(i, priorities[i]));
        pque.push(priorities[i]);
    }

    while(pque.size() > 0)
    {
        int idx = que.front().first;
        int value = que.front().second;
        que.pop();
        
        if(value == pque.top())
        {
            pque.pop();
            answer++;
            if(idx == location)
                break;
        }
        else
            que.push(make_pair(idx,value));
        
        
    }

    
    return answer;
}