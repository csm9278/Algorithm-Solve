#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

struct Pos
{
    public:
    int y;
    int x;
};

int mapSize =0;
int arr[21][21] = {0};
bool visited[21][21] = {false};
int nowY, nowX;

int level = 2;
int expCnt = 0;
int answer = 0;

int dy[4] = {-1, 0, 0, 1};  //상단 좌측 우선
int dx[4] = {0, -1, 1, 0};

void Input()
{
    cin >> mapSize;

    for(int i = 0; i < mapSize; i++)
    for(int j = 0; j < mapSize; j++)
    {
        int num;
        cin >> num;

        if(num != 9)
            arr[i][j] = num;
        else
        {
            arr[i][j] = 0;
            nowY = i;
            nowX = j;
        }

    }
}

bool BFS(int startY, int startX)
{
    queue<pair<Pos, int>> ques;
    ques.push({{startY, startX}, 0});
    
    memset(visited, false, sizeof(visited));
    visited[startY][startX] = true;

    Pos target;
    int minNum = INT_MAX;

    bool findTarget = false;

    while(!ques.empty())
    {
        Pos front = ques.front().first;
        int moveTime = ques.front().second;
        ques.pop();

        for(int i = 0; i < 4; i++)
        {
            Pos goPos;
            goPos.y = front.y + dy[i];
            goPos.x = front.x + dx[i];

            if(0 <= goPos.y && goPos.y < mapSize && 0 <= goPos.x && goPos.x < mapSize)  //맵 사이즈 체크
            if(!visited[goPos.y][goPos.x] && arr[goPos.y][goPos.x] <= level) // 방문 중복 & 상어 사이즈 체크
            {
                int nextMove = moveTime + 1;
                
                visited[goPos.y][goPos.x] = true;   //방문 처리
                ques.push({goPos, nextMove});   //큐 등록

                if(0 < arr[goPos.y][goPos.x] && arr[goPos.y][goPos.x] < level)  //사냥감일시
                if(minNum > nextMove)   //최저 이동경로
                {
                    minNum = nextMove;
                    target = goPos;
                    findTarget = true;
                }
                else if(minNum == nextMove)
                if (goPos.y < target.y || (goPos.y == target.y && goPos.x < target.x))
                            target = goPos; // y↑, x↑ 타이브레이크
            }
        }
    }

    //최단 경로 물고기 섭취
    if(findTarget)
    {
        arr[target.y][target.x] = 0;
        expCnt++;
        if(expCnt >= level)
        {
            level++;
            expCnt = 0;
        }


        nowY = target.y;
        nowX = target.x;
        answer += minNum;   //이동 량 추가
        return findTarget;
    }

    return findTarget;
}

void Solve()
{
    while(true)
    {
        bool canEat = BFS(nowY, nowX);

        if(!canEat)
            break;
    }

    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Solve();

    return 0;
}