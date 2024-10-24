#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k;
int arr[101][101] = {0};
bool visited[101][101] = {false};
vector<int> sizeVec;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int answer = 0;

void Input()
{
    cin >> n >> m >> k;

    for(int q =0 ; q < k; q++)
    {
        int originY, originX, targetY, targetX;

        cin >> originX >> originY >> targetX >> targetY;

        for(int i = originY; i < targetY; i++)
        {
            for(int j = originX; j < targetX; j++)
            {
                arr[i][j] = 1;
                visited[i][j] = true;
            }
        }
    }
}

void BFS(int y, int x)
{
    visited[y][x] = true;
    queue<pair<int,int>> ques;
    ques.push({y, x});
    int curSize = 1;
    
    while(!ques.empty())
    {
        int y = ques.front().first;
        int x = ques.front().second;
        ques.pop();

        for(int i = 0; i < 4; i++)
        {
            int gy = y + dy[i];
            int gx = x + dx[i];

            if(gy < n && gy >= 0 && gx < m && gx >= 0)
            if(!visited[gy][gx])
            {
                ques.push({gy, gx});
                visited[gy][gx] = true;
                curSize++;
            }
        }
    }

    answer++;
    sizeVec.push_back(curSize);
}

void Solve()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 0 && !visited[i][j])
            {
                BFS(i,j);
            }
        }
    }
}

int main()
{
    Input();
    Solve();
    cout << answer << endl;

    sort(sizeVec.begin(), sizeVec.end());
    for(int i = 0; i < sizeVec.size(); i++)
        cout << sizeVec[i] << " ";

    return 0;
}