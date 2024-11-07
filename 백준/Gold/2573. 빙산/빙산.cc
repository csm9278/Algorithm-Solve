#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int n, m;
int answer = 0;
int arr[301][301] = {0};
bool noIce[301][301] = {false};
bool visited[301][301] = {false};
vector<pair<int,int>> ice;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void Input()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
    {
        cin >> arr[i][j];
        if(arr[i][j] == 0)
            noIce[i][j] = true;
        else
            ice.push_back({i,j});
    }
}

void Check()
{
    queue<pair<int,int>> que;

}

void BFS(int y, int x)
{
    queue<pair<int,int>> que;
    que.push({y,x});
    visited[y][x] = true;

    while(!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++)
        {
            int gy = y + dy[i];
            int gx = x + dx[i];

            if(gy >= 0 && gy < n && gx >= 0 && gx < m)
            if(!noIce[gy][gx] && !visited[gy][gx])
            {
                que.push({gy,gx});
                visited[gy][gx] = true;
            }
        }
    }
}

void IceMelt()
{
        memset(visited, false, sizeof(visited));
        
        for (int i = ice.size() - 1; i >= 0; i--) 
        {
            int y = ice[i].first;
            int x = ice[i].second;
            if (noIce[y][x]) 
                continue;

            int meltCount = 0;
            for(int j = 0; j < 4; j++)
            {
                int gy = y + dy[j];
                int gx = x + dx[j];

                if(gy >= 0 && gy < n && gx >= 0 && gx < m)
                if(arr[gy][gx] <= 0 && !visited[gy][gx])
                    meltCount++;

            }

            arr[y][x] -= meltCount;
            visited[y][x] = true;
            if (arr[y][x] <= 0)
            {
                noIce[y][x] = true;
                ice.erase(ice.begin() + i);
            }
        }
        answer++;
}

void Solve()
{
    while(answer < 10001)
    {
        int iceArea = 0;
        memset(visited, false, sizeof(visited));

        for(int i = 0; i < ice.size(); i++)
        {
            int y = ice[i].first;
            int x = ice[i].second;

            if(!visited[y][x])
            {
                BFS(y, x);
                iceArea++;
            }
        }

        if(iceArea > 1)
            break;

        IceMelt();

    }

    if(answer > 10000)
        cout << 0;
    else
        cout << answer;
}

int main()
{
    Input();
    Solve();
    return 0;
}