#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> qq;
    priority_queue<int> ques;
    for(int i = 0 ; i < priorities.size(); i++)
    {
        qq.push({priorities[i], i});
        ques.push(priorities[i]);
    }
    
    while(!ques.empty())
    {
        pair<int, int> q = qq.front();
        qq.pop();
        int n = ques.top();
        
        if(n == q.first)
        {
            answer++;
            if(q.second == location)
            {
                break;
            }
            ques.pop();
        }
        else
            qq.push(q);
        
    }
    
    return answer;
}