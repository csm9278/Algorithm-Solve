#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int needP[8];
int payP[8];
int dsize;
int check[8] ={false};
int result = -1;

void dfs(int count, int k)
{
    for(int i = 0; i < dsize; i++)
        if(needP[i] <= k && !check[i])
        {
            check[i] = true;
            dfs(count + 1, k - payP[i]);
            check[i] = false;
        }
    
    result = max(count, result);
    return;
}

int solution(int k, vector<vector<int>> dungeons) 
{
    int answer = 0;
    dsize = dungeons.size();
    for(int i = 0; i < dungeons.size(); i++)
    {
        needP[i] = dungeons[i][0];
        payP[i] = dungeons[i][1];
    }
    
    dfs(0, k);
    return result;
}