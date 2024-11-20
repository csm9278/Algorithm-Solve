#include <iostream>
#include <queue>
using namespace std;

struct Pos
{
    public:
        int x;  
        int y;
};

int n, m;
int arr[51][51] = {0};
bool isClean[51][51] = {false};
Pos pos;
int rotation;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int by[4] = {1, 0, -1, 0};  //후진용
int bx[4] = {0, -1, 0, 1};    
int answer = 0;

void Input()
{
    cin >> n >> m;
    cin >> pos.y >> pos.x >> rotation;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        cin >> arr[i][j];
}

void Rotate()
{
    rotation--;
    if(rotation < 0)
        rotation = 3;
}

bool CheckDust(int y, int x)
{
    for(int i = 0 ; i < 4; i++)
    {
        int gy = y + dy[i];
        int gx = x + dx[i];
        if(gy >= 0 && gy < n && gx >= 0 && gx < m)
            if(arr[gy][gx] == 0 && !isClean[gy][gx])
                return true;

    }

    return false;
}


void Solve()
{
    while(true)
    {
        if(!isClean[pos.y][pos.x])
        {
            isClean[pos.y][pos.x] = true;
            answer++;
        }

        bool check = CheckDust(pos.y, pos.x);
        int gy, gx;

        if(check)   //주변에 먼지가 있는경우
        {
            Rotate();
            gy = pos.y + dy[rotation];
            gx = pos.x + dx[rotation];

            if(gy >= 0 && gy < n && gx >= 0 && gx < m)
            if(arr[gy][gx] == 0 && !isClean[gy][gx])
            {
                pos.y = gy;
                pos.x = gx;
            }
        }
        else    //주변에 먼지가 없는 경우 후진
        {
            gy = pos.y + by[rotation];
            gx = pos.x + bx[rotation];

            if(gy >= 0 && gy < n && gx >= 0 && gx < m)
            if(arr[gy][gx] == 1)
                break;
            else
            {
                pos.y = gy;
                pos.x = gx;
            }
        }
    }
    cout << answer;
}

int main()
{
    Input();
    Solve();

    return 0;
}