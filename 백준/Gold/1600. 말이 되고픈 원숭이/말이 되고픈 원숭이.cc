#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Pos
{
    public:
    int y;
    int x;
};

struct Move
{
    public:
    int move;
    int jumpCnt;
};

Pos maxPos;
int jump;
int arr[201][201];
bool visited[201][201][31] = {false};
int answer = INT_MAX;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int jy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int jx[8] = {1, 2, 2, 1, -1, -2, -2, -1};


void Input()
{
    cin >> jump;
    cin >> maxPos.x >> maxPos.y;
    for(int i = maxPos.y - 1; i >= 0; i--)
    for(int j = 0; j < maxPos.x; j++)
    {
        cin >> arr[i][j];
    }
}

void BFS()
{
    queue<pair<Pos, Move>> ques;
    ques.push({{maxPos.y - 1, 0}, {0, jump}});  //제일 왼쪽 위 시작지점;
    visited[maxPos.y - 1][0][jump] = true;

    while(!ques.empty())
    {
        Pos front = ques.front().first;
        Move moves = ques.front().second;
        ques.pop();

        //도착판정
        if(front.y == 0 && front.x == maxPos.x - 1)
        {
            if(answer > moves.move)
                answer = moves.move;

            continue;
        }

        //사각 격자 이동
        for(int i = 0; i < 4; i++)
        {
            Pos gPos = {front.y + dy[i], front.x + dx[i]};

            if(0 <= gPos.y && gPos.y < maxPos.y && 0 <= gPos.x && gPos.x < maxPos.x)
            if(arr[gPos.y][gPos.x] == 0 && !visited[gPos.y][gPos.x][moves.jumpCnt])
            {
                Move mv = {moves.move + 1, moves.jumpCnt};

                ques.push({gPos, mv});
                visited[gPos.y][gPos.x][mv.jumpCnt] = true;
            }
        }

        //점프 횟수가 남아있다면
        if(moves.jumpCnt > 0)
        for(int i = 0; i < 8; i++)
        {
            Pos gPos = {front.y + jy[i], front.x + jx[i]};

            if(0 <= gPos.y && gPos.y < maxPos.y && 0 <= gPos.x && gPos.x < maxPos.x)
            if(arr[gPos.y][gPos.x] == 0 && !visited[gPos.y][gPos.x][moves.jumpCnt - 1])
            {
                Move mv = {moves.move + 1, moves.jumpCnt - 1};

                ques.push({gPos, mv});
                visited[gPos.y][gPos.x][mv.jumpCnt] = true;
            }
        }
    }

    if(answer != INT_MAX)
        cout << answer;
    else
        cout << -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    BFS();
    return 0;
}