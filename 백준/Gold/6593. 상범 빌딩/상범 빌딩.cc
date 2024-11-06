#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <limits.h>
using namespace std;

int h, n, m;
char arr[31][31][31];
bool visited[31][31][31] = {false};
int dh[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 0, 1, 0};
int dx[6] = {0, 0, 0, 1, 0, -1};

tuple<int, int, int> start;
tuple<int,int,int> target;

int answer = INT_MAX;

void Input()
{
    memset(visited, false, sizeof(visited));
    answer = INT_MAX;

    cin >> h >> n >> m;

    for(int i = 0; i < h; i++)
    for(int j = 0; j < n; j++)
    for(int k = 0; k < m; k++)
    {
        char c;
        cin >> c;

        if(c == '#')
            visited[i][j][k] = true;
        else if(c == 'S')
            start = {i, j, k};
        else if(c == 'E')
            target = {i, j, k};

        arr[i][j][k] = c;
    }

}

void BFS(tuple<int,int,int> pos)
{
    queue<pair<tuple<int,int,int>, int>> que;
    que.push({pos, 0});

    while(!que.empty())
    {
        if(que.front().first == target)
        {
            answer = que.front().second;
            break;
        }

        int height = get<0>(que.front().first);
        int y = get<1>(que.front().first);
        int x = get<2>(que.front().first);
        int count = que.front().second;
        que.pop();

        for(int i = 0; i < 6; i++)
        {
            int gh = height + dh[i];
            int gy = y + dy[i];
            int gx = x + dx[i];

            if(gh >= 0 && gh < h && gy >= 0 && gy < n && gx >=0 && gx < m)
            if(!visited[gh][gy][gx] && arr[gh][gy][gx] != '#')
            {
                que.push({{gh, gy, gx}, count + 1});
                visited[gh][gy][gx] = true;
            }
        }

    }
}

void Solve()
{
    BFS(start);
    if(answer == INT_MAX)
        cout << "Trapped!" << endl;
    else
        cout << "Escaped in " << answer << " minute(s)." << endl;
}

int main()
{
    while(true)
    {
        Input();

        if(h == 0 && n == 0 && m == 0)
            break;

        Solve();
    }


    return 0;
}