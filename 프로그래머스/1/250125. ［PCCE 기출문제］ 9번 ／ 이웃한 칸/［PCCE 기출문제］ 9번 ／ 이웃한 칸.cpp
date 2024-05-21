#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    string target = board[h][w];
    
    for(int i = 0 ; i < 4; i++)
    {
        int x = h + dx[i];
        int y = w + dy[i];
        
        if(x < 0 || board.size() <= x ||
           y < 0 || board[0].size() <= y)
            continue;
        
        if(board[x][y] == target)
            answer++;

    }
    
    return answer;
}