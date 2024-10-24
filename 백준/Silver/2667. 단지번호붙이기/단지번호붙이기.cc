#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[26][26];
bool visited[26][26] = {false};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
int bNum = 0;
vector<int> sizeVec;

void Input()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++)
            arr[i][j] = s[j] - '0';
    }
}

int DFS(int y, int x, int count)
{
    visited[y][x] = true;

    for(int i = 0; i < 4; i++)
    {
        int gy = y + dy[i];
        int gx = x + dx[i];

        if(gy < n && gy >= 0 && gx < n && gx >= 0)
        if(!visited[gy][gx] && arr[gy][gx] == 1)
        {
            count = DFS(gy, gx, count + 1);
        }
    }

    return count;
}

void Solve()
{
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
        if(arr[i][j] == 1 && !visited[i][j])
        {
            bNum++;
            sizeVec.push_back(DFS(i,j,1)); 
        }
    }
}

int main()
{
    Input();
    Solve();

    cout << bNum << endl;

    sort(sizeVec.begin(), sizeVec.end());
    for(int i = 0 ; i < sizeVec.size(); i++)
        cout << sizeVec[i] << endl;

    return 0;
}