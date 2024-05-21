#include<vector>
#include<queue>
#include<iostream>
using namespace std;

bool visited[101][101] = {false};
int dx[4] = {-1, 1 , 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<vector<int> > maps)
{
    int answer = 1;
    
    queue<pair<int,int>> ques;
    ques.push({0, 0});
    visited[0][0] = true;
    
    int xSize = maps[0].size() - 1;
    int ySize = maps.size() - 1;
    
    
    while(!ques.empty())
    {
        int x = ques.front().second;
        int y = ques.front().first;
        ques.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int gx = x + dx[i];
            int gy = y + dy[i];
            if(0 <= gy && gy <= ySize && 0 <= gx && gx <= xSize)
            {
                if(visited[gy][gx])
                    continue;
                if(maps[gy][gx] <= 0)
                    continue;
                ques.push({gy, gx});
                maps[gy][gx] = maps[y][x] + 1;
                visited[gy][gx] = true;
            }
        }
    }
    
    return maps[ySize][xSize] == 1 ? -1 : maps[ySize][xSize];
}