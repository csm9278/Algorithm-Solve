#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) 
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> que;
    
    if(enemy.size() == k)
    {
        answer = k;
        return answer;
    }
    
    for(int i = 0 ; i < enemy.size(); i++)
    {
        int num = enemy[i];
        que.push(num);
        
        if(que.size() > k)
        {
            n -= que.top();
            que.pop();
            
            if(n >= 0)
                answer++;
            else
                return answer;
        }
        else
            answer++;
        
    }
    
    
    return answer;
}