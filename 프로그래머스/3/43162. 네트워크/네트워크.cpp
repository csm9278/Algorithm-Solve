#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool visited[201] = {false};

void DP(int comNum, int n, vector<vector<int>> computers)
{
    visited[comNum] = true;
    
    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && computers[comNum][i])
            DP(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i =0; i < n; i++)
    {
        if(!visited[i])
        {
            DP(i, n, computers);
            answer++;
        }
        
    }
    
    return answer;
}