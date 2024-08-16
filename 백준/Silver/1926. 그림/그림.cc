#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> vecs;
bool visited[501][501] = {false};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int answer, maxAns;


void Input()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        vector<int> v;
        for(int j = 0; j < m; j++)
        {
            int c;
            cin >> c;
            v.push_back(c);
        }
        vecs.push_back(v);
    }
}

void DFS(int y, int x)
{
    queue<pair<int, int>> ques;
    ques.push({y, x});
    visited[y][x] = true;
    int curNum = 1;

    while(!ques.empty())
    {

        int nx = ques.front().second;
        int ny = ques.front().first;
        ques.pop();

        for(int i = 0; i < 4; i++)
        {
            int gx = nx + dx[i];
            int gy = ny + dy[i];
            if(0 <= gx && gx < m && 0 <= gy && gy < n)
            {
                if(!visited[gy][gx] && vecs[gy][gx] == 1)
                {
                    ques.push({gy, gx});
                    visited[gy][gx] = true;
                    curNum++;
                }
            }          

        }
    }
    maxAns = std::max(maxAns, curNum);
}

void Solve()
{
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
    {
        if(vecs[j][i] == 1 && !visited[j][i])
        {
            DFS(j, i);
            answer++;
        }
    }

    cout << answer << endl;
    cout << maxAns;
}

int main()
{
    Input();
    Solve();
}