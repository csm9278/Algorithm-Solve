#include <iostream>
#include <queue>
using namespace std;

int n;
int answer = 1;
bool isSink[101][101] = {false};
bool visited[101][101] = {false};
int arr[101][101] = {0};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int maxArea = 1;
int maxHeight = 0;

void Input()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
        int h;
        cin >> h;
        arr[i][j] = h;
        maxHeight = max(maxHeight, h);
    }
}

void ClearVisited()
{
    for(int i = 0; i < 101; i++)
    for(int j = 0; j < 101; j++)
        visited[i][j] = false;
}

void BFS(int y, int x)
{
    queue<pair<int,int>> que;
    que.push({y, x});

    while(!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();


        for(int i = 0; i < 4; i++)
        {
            int gy = y + dy[i];
            int gx = x + dx[i];

            if(gy >= 0 && gy < n && gx >= 0 && gx < n)
            if(!visited[gy][gx] && !isSink[gy][gx])
            {
                que.push({gy, gx});
                visited[gy][gx] = true;
            }
        }

    }
}

void Solve()
{
    int curHeight = 1;

    while(curHeight < maxHeight)
    {
        int curArea = 0;

        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
        {
            if(arr[i][j] == curHeight)
                isSink[i][j] = true;
        }

        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(!isSink[i][j] && !visited[i][j])
            {
                visited[i][j] = true;
                BFS(i,j);

                curArea++;
            }
        }

        maxArea = max(maxArea, curArea);
        ClearVisited();
        curHeight++;
    }

}

int main()
{
    Input();
    Solve();
    cout << maxArea;
    return 0;
}