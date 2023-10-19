#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int tan[10000001] = {0};

int solution(int k, vector<int> tangerine) 
{
    int answer = 0;
    priority_queue<int> ques;
    
    for(int i = 0 ; i < tangerine.size(); i++)
    {
        tan[tangerine[i]]++;
        if(tan[tangerine[i]] == k)
            return 1;
    }
    
    for(int i = 0 ; i < 10000001; i++)
    {
        ques.push(tan[i]);
    }
    
    while(!ques.empty())
    {
        int num = ques.top();
        ques.pop();
        k -= num;
        answer++;
        if(k <= 0)
            break;
    }
    

    
    return answer;
}