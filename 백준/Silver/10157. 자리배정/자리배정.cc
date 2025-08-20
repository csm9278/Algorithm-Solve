#include <iostream>
using namespace std;

int maxX, maxY;
int target;

bool arr[1001][1001] = {false};
int y = 1, x = 1;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void Input()
{
    cin >> maxX >> maxY >> target;
}

bool Solve()
{
    int dir = 0;
    int move = 1;
    
    if(1LL*maxX * maxY < target)
        return false;
    
    arr[1][1] = true;
    while(move < target)
    {
        int gy = y + dy[dir];
        int gx = x + dx[dir];
        if(gy < 1 || gx < 1 || gy > maxY || gx > maxX || arr[gy][gx])
        {
            dir = (dir + 1) % 4;
            continue;
        }

        y = gy; x = gx;
        arr[y][x] = true;
        move++;
    }

    return true;
}

int main()
{
    Input();
    if(Solve())
        cout << x << " " << y;
    else
        cout << 0;
    return 0;
}