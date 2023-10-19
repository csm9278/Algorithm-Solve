#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int board[101][101] = { 0 };
int maxX, maxY;

int DP(queue<pair<pair<int, int>, int>>& ques, pair<int, int> target)
{
    bool visited[101][101] = { false };

    while (!ques.empty())
    {
        int y = ques.front().first.first;
        int x = ques.front().first.second;
        int move = ques.front().second;
        ques.pop();

        if (visited[y][x] || board[y][x] < 0)
            continue;
        else
        {
            if (y < 0 || y >= maxY || x < 0 || x >= maxX)
                continue;

            visited[y][x] = true;
            if (board[y][x] != 0) min(board[y][x], move);
            if (target.first == y && target.second == x)
                return move;
            ques.push({ {y + 1, x}, move + 1 });
            ques.push({ {y, x + 1}, move + 1 });
            ques.push({ {y - 1, x}, move + 1 });
            ques.push({ {y, x - 1}, move + 1 });
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    pair<int, int> start;
    pair<int, int> lever;
    pair<int, int> exit;
    queue<pair<pair<int, int>, int>> ques;

    //Init
    maxX = maps[0].size();
    maxY = maps.size();

    for (int y = 0; y < maps.size(); y++)
        for (int x = 0; x < maps[y].size(); x++)
        {
            if (maps[y][x] == 'S')
                start = { y, x };
            else if (maps[y][x] == 'L')
                lever = { y,x };
            else if (maps[y][x] == 'E')
                exit = { y,x };
            else if (maps[y][x] == 'X')
                board[y][x] =  -1;
        }

    //Main
    int leverCount, exitCount;
    ques.push({ start, 0 });
    leverCount = DP(ques, lever);
    if(leverCount < 0) return -1;
    ques = queue<pair<pair<int, int>, int>>();
    ques.push({ lever, board[lever.first][lever.second] });
    exitCount = DP(ques, exit);
    if(exitCount < 0) return -1;
    
    return leverCount + exitCount;
}