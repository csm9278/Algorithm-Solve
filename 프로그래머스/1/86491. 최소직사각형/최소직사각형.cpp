#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int answer = 0;
    int maxW = 0, maxH = 0;
    
    for(int i = 0; i < sizes.size(); i++)
    {
        int large = max(sizes[i][0], sizes[i][1]);
        int small = min(sizes[i][0], sizes[i][1]);
        
        maxW = max(maxW, large);
        maxH = max(maxH, small);
        
    }
    answer = maxH * maxW;
    return answer;
}