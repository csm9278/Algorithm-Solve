#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int n, m;
char arr[1001][1001];
bool visited[1001][1001];

int answer;
int second = 0;
queue<pair<int,int>> fque;

pair<int,int> startPos;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void Input()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] == '#')
                visited[i][j] = true;
            else if(s[j] == 'J')
                startPos = {i,j};
            else if(s[j] == 'F')
            {
                fque.push({i,j});
                visited[i][j] = true;
            }

            arr[i][j] = s[j];
        }
    }
}

void Solve()
{
    queue<pair<int,int>> jque;

    jque.push(startPos);

    while(!jque.empty())
    {
        //불 관련 이동
        int fqueSize = fque.size();
        for(int i = 0; i < fqueSize; i++)
        {
            int y = fque.front().first;
            int x = fque.front().second;
            fque.pop();

            for(int j = 0; j < 4; j++)
            {
                int gy = y + dy[j];
                int gx = x + dx[j];

                if(gy < n && gy >= 0 && gx < m && gx >= 0)
                if(!visited[gy][gx])
                {
                    fque.push({gy,gx});
                    visited[gy][gx] = true;
                }
            }
        }

        //지훈 이동
        int jqueSize = jque.size();

        for(int i = 0; i < jqueSize; i++)
        {
            int y = jque.front().first;
            int x = jque.front().second;
            jque.pop();
            
            for(int j = 0; j < 4; j++)
            {
                int gy = y + dy[j];
                int gx = x + dx[j];

                if(gy < n && gy >= 0 && gx < m && gx >= 0)
                {
                    if(!visited[gy][gx])
                    {
                        jque.push({gy,gx});
                        visited[gy][gx] = true;
                    }
                }
                else
                {
                    cout << second + 1;
                    jque = queue<pair<int,int>>();
                    return;
                }
                
            }
        }
        second++;
    }
    cout << "IMPOSSIBLE";
}

int main()
{
    Input();
    Solve();

    return 0;
}