#include <iostream>
#include <vector>
using namespace std;

int y, x;
int nowY, nowX;
vector<int> dice(6, 0);//위 동 서 남 북 아래
int order = 0;

int dy[4] = {0, 0, -1, 1};  //동서남북
int dx[4] = {1, -1, 0, 0};

void SwapDice(int dir)
{
    switch (dir)
    {
        case 0: //동 이동시
            dice = {dice[2], dice[0], dice[5], dice[3], dice[4], dice[1]};
            break;

        case 1: //서 이동시
            dice = {dice[1], dice[5], dice[0], dice[3], dice[4], dice[2]};
            break;

        case 2: //남 이동시
            dice = {dice[4], dice[1], dice[2], dice[0], dice[5], dice[3]};
            break;

        case 3: //북 이동시
            dice = {dice[3], dice[1], dice[2], dice[5], dice[0], dice[4]};
            break;
    }

}

int arr[21][21] = {0}; 

void Input()
{
    cin >> y >> x;
    cin >> nowY >> nowX;
    cin >> order;
    for(int i = 0; i < y; i++)
    for(int j = 0; j < x; j++)
    {
        int num;
        cin >> num;
        arr[i][j] = num;
    }
}

void Solve()
{
    for(int i =0; i < order; i++)
    {
        int dir;
        cin >> dir;
        dir--;
        int gy = nowY + dy[dir];
        int gx = nowX + dx[dir];

        if(gy < 0 || y <= gy || gx < 0 || x <= gx)
        {
            continue;
        }

        SwapDice(dir);

        nowY = gy;
        nowX = gx;
        if(arr[gy][gx] == 0)
            arr[gy][gx] = dice[5];
        else
        {
            dice[5] = arr[gy][gx];
            arr[gy][gx] = 0;
        }
        cout << dice[0] << endl;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Solve();
    return 0;
}