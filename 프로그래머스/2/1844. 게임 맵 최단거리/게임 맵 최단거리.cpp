#include<vector>
#include<queue>
using namespace std;

bool visited[101][101];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue<pair<int,int>> ques;
    ques.push({0, 0});
    visited[0][0] = true;
    
    int ySize = maps.size() - 1;
    int xSize = maps[0].size() - 1;
    
    while(!ques.empty())
    {
        int y = ques.front().first;
        int x = ques.front().second;
        ques.pop();
        
        for(int i = 0 ; i < 4; i++)
        {
            int gy = y + dy[i];
            int gx = x + dx[i];
            
            if(0 <= gy && gy <= ySize && 0 <= gx && gx <= xSize)
            if(!visited[gy][gx] && maps[gy][gx] > 0)
            {
                visited[gy][gx] = true;
                maps[gy][gx] = maps[y][x] + 1;
                ques.push({gy, gx});
            }
        }
    }
    
    if(maps[ySize][xSize] == 1)
        return -1;
    else
        return maps[ySize][xSize];
}