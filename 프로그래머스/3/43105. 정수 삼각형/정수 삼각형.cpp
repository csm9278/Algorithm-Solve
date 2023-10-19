#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int anstri[501][501] = {0};


int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    for(int i =1; i < size; i++)
        for(int j =0; j < triangle[i].size(); j++)
            if(j == 0)
                triangle[i][j] = triangle[i][j] + triangle[i - 1][j];
            else if(j == triangle[i].size() - 1)
                triangle[i][j] = triangle[i][j] + triangle[i - 1][j - 1];
            else
            {
                int a, b;
                a = triangle[i][j] + triangle[i - 1][j - 1];
                b = triangle[i][j] + triangle[i - 1][j];
                a > b ? triangle[i][j] = a : triangle[i][j] = b; 
            }
    sort(triangle[size - 1].begin(), triangle[size - 1].end());

    return triangle[size - 1][size - 1];
}