#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int n;
char arr[101][101];
bool visited[101][101];
bool visited2[101][101];

int answer, answer2;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void Input()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++)
            arr[i][j] = s[j];
    }

}


void BFS(int y, int x)
{
    queue<pair<int,int>> ques;
    ques.push({y, x});
    visited[y][x];

    char target = arr[y][x];
    while(!ques.empty())
    {
        int y = ques.front().first;
        int x = ques.front().second;
        ques.pop();

        for(int i = 0; i < 4; i++)
        {
            int gy = y + dy[i];
            int gx = x + dx[i];

            if(gy < n && gy >= 0 && gx < n && gx >= 0)
            if(!visited[gy][gx] && arr[gy][gx] == target)
            {
                ques.push({gy, gx});
                visited[gy][gx] = true;
            }
        }
    }

    answer++;
}

void BFS2(int y, int x)
{
    queue<pair<int,int>> ques;
    ques.push({y, x});
    visited[y][x];

    char target = arr[y][x];
    while(!ques.empty())
    {
        int y = ques.front().first;
        int x = ques.front().second;
        ques.pop();

        for(int i = 0; i < 4; i++)
        {
            int gy = y + dy[i];
            int gx = x + dx[i];

            if(gy < n && gy >= 0 && gx < n && gx >= 0)
            if(!visited2[gy][gx])
            if(target == 'R' || target =='G' ? 
              arr[gy][gx] == 'R' || arr[gy][gx] == 'G':
              arr[gy][gx] == target)
            {
                ques.push({gy, gx});
                visited2[gy][gx] = true;
            }
        }
    }

    answer2++;
}

void Solve()
{
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
        if(!visited[i][j])
            BFS(i, j);
    }

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
        if(!visited2[i][j])
            BFS2(i, j);
    }
}



int main()
{
    Input();
    Solve();

    cout << answer << " " << answer2;
    return 0;
}