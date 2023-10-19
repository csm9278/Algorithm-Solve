#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int map[101][101] = {0};
    
    for(int i = 0; i < 101; i++)
        for(int j = 0 ; j < 101; j++)
            map[i][j] = -1;
    
    for(int i =0; i < puddles.size(); i++)
        map[puddles[i][1] - 1][puddles[i][0] - 1] = 0;

    map[0][0] = 1;
        for(int y = 0; y < n; y++)
            for(int x = 0; x < m; x++)
            {
                if(map[y][x] == -1)
                if(map[y][x] == 0)
                    continue;
                else if(y == 0)
                    map[y][x] = map[y][x - 1];
                else if(x == 0)
                    map[y][x] = map[y - 1][x];
                else
                    map[y][x] = (map[y - 1][x] + map[y][x - 1]) % 1000000007; 
            }

    return map[n - 1][m - 1];
}