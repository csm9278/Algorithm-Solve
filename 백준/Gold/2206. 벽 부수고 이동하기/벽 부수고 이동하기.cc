#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

int n, m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int answer = INT_MAX;

int arr[1001][1001];
bool visited[1001][1001][2];

struct SPos
{
    public:
    pair<int, int> pos;
    int count;
    bool canBreak;

    public:
    SPos(int y, int x, int c, bool cB)
    {
        pos = {y, x};
        count = c;
        canBreak = cB;
    }
};

void Input()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++)
        {
            arr[i][j] = s[j] - '0';
        }
    }
}

void BFS(int y, int x, int count)
{
    queue<SPos> ques;
    ques.push(SPos(0, 0, 1, true));
    visited[0][0][1] = true;

    while(!ques.empty())
    {
        SPos sp = ques.front();
        int y = sp.pos.first;
        int x = sp.pos.second;
        ques.pop();
        if(y == n - 1 && x == m - 1)
        {
            answer = min(sp.count, answer);
            continue;
        }

        for(int i = 0 ; i < 4; i++)
        {
            int gy = y + dy[i];
            int gx = x + dx[i];

            if(gy >= 0 && gy < n && gx >= 0 && gx < m)
            if(arr[gy][gx] == 0)
            {
                if(!visited[gy][gx][sp.canBreak])
                {
                    ques.push(SPos(gy, gx, sp.count + 1, sp.canBreak));
                    visited[gy][gx][sp.canBreak] = true;
                }
            }
            else
            {
                if(!visited[gy][gx][0] && sp.canBreak)
                {
                    ques.push(SPos(gy, gx, sp.count + 1, false));
                    visited[gy][gx][0] = true;
                }
            }

        }
    }
}

void Solve()
{
    BFS(0, 0, 1);
}

int main()
{
    Input();
    Solve();
    if(answer == INT_MAX)
        cout << -1;
    else
        cout << answer;
    return 0;
}