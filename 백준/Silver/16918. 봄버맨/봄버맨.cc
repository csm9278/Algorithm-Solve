#include <iostream>
using namespace std;

int arr[201][201] = {0};
int second = 1;
int n, m, k;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};


void Input()
{
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] == '.')
                arr[i][j] = 0;
            else
                arr[i][j] = 2;
        }
    }
}

void Solve()
{
    k-=1;
    while(--k >= 0)
    {
        bool visited[201][201] = {false};


        for(int y = 0; y < n; y++)
        for(int x = 0; x < m; x++)
        {
            if(arr[y][x] != 0)
            {
                //폭발
                if(arr[y][x] - 1 <= 0)
                {
                    for(int i = 0; i < 4; i++)
                    {
                        int gy = y + dy[i];
                        int gx = x + dx[i];

                        if(gy >= 0 && gy < n && gx >= 0 && gx < m)
                        if(arr[gy][gx] != 1)
                        {
                            visited[gy][gx] = true;
                            arr[gy][gx] = 0;
                        }
                    }

                    visited[y][x] = true;
                    arr[y][x] = 0;
                }

                //타이머 감소
                if(!visited[y][x])
                    arr[y][x]--;
            }
            else
            {
                if(!visited[y][x])
                {
                    visited[y][x] = true;
                    arr[y][x] = 3;
                }
            }

        }
    }

    for(int i = 0; i < n; i++)
    {
        string s = "";
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] > 0)
                s += 'O';
            else
                s += '.';
        }
        cout << s << endl;
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}
