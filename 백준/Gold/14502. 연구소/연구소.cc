#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <limits>
using namespace std;

struct Pos
{
    public:
    int y;
    int x;
};

Pos maxPos;
vector<vector<int>> area;
vector<Pos> virusVec;
vector<vector<bool>> visited;
vector<Pos> emptyVec;

int maxCount = 0;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

vector<vector<int>> FillVirus(vector<vector<int>> cloneArea, vector<vector<bool>> cloneVisited)
{
    queue<Pos> ques;

    for(int i = 0; i < virusVec.size(); i++)    //바이러스 입장
        ques.push(virusVec[i]);

    while(!ques.empty())
    {
        Pos nowPos = ques.front();

        for(int i = 0; i < 4; i++)
        {
            Pos goPos = {nowPos.y + dy[i], nowPos.x + dx[i]};

            if(0 <= goPos.y && goPos.y < maxPos.y && 0 <= goPos.x && goPos.x < maxPos.x)
            if(!cloneVisited[goPos.y][goPos.x] && cloneArea[goPos.y][goPos.x] == 0)
            {
                cloneVisited[goPos.y][goPos.x] = true;
                cloneArea[goPos.y][goPos.x] = 2;
                ques.push(goPos);
            }
        }

        ques.pop();
    }

    return cloneArea;
}

void Input()
{
    cin >> maxPos.y >> maxPos.x;

    for(int i = 0; i < maxPos.y; i++){
        vector<int> vecs;
        vector<bool> visit;
        for(int j = 0; j < maxPos.x; j++)
        {
            int num;
            cin >> num;

            if(num == 2)
                virusVec.push_back({i, j});

            if(num != 0)
                visit.push_back(true);
            else
            {
                emptyVec.push_back({i,j});
                visit.push_back(false);
            }

            vecs.push_back(num);
        }
        area.push_back(vecs);
        visited.push_back(visit);
    }
}

void Solve()
{
    int zeroCnt = 0;
    for(int i = 0; i < emptyVec.size(); i++)
    for(int j = i + 1; j < emptyVec.size(); j++)
    for(int k = j + 1; k < emptyVec.size(); k++)
    {
        auto cloneArea = area;
        auto cloneVisited = visited;
        cloneArea[emptyVec[i].y][emptyVec[i].x] = 1;
        cloneVisited[emptyVec[i].y][emptyVec[i].x] = true;
        cloneArea[emptyVec[j].y][emptyVec[j].x] = 1;
        cloneVisited[emptyVec[j].y][emptyVec[j].x] = true;
        cloneArea[emptyVec[k].y][emptyVec[k].x] = 1;
        cloneVisited[emptyVec[k].y][emptyVec[k].x] = true;

        auto filled = FillVirus(cloneArea, cloneVisited);

        zeroCnt = 0;
        for(int i = 0; i < filled.size(); i++)
        for(int j = 0; j < filled[i].size(); j++)
            if(filled[i][j] == 0)
                zeroCnt++;

        if(maxCount < zeroCnt)
            maxCount = zeroCnt;
    }
    cout << maxCount;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Solve();

    return 0;
}