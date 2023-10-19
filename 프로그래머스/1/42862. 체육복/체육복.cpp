#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool st[31] = {false};
int re[31] = {-1};

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i = 0; i < reserve.size(); i++)
    {
        re[reserve[i]] = 1;
    }
    
    for(int i = 0 ; i < lost.size(); i++)
    {
        if(re[lost[i]] == 1)
        {
            st[lost[i]] = true;
            answer++;          
        }
    }
    
    for(int i = 0 ; i < lost.size(); i++)
    {
        if(st[lost[i]] == true)
            continue;
        
        if(re[lost[i] - 1] == 1 && st[lost[i] - 1] == false)
        {
            answer++;
            st[lost[i] - 1] = true;
        }
        else if(re[lost[i] + 1] == 1 && st[lost[i] + 1] == false)
        {
            answer++;
            st[lost[i] + 1] = true;
        }
    }
    
    
    return answer;
}