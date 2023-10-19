#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    if(score.size() < m)
        return answer;
    
    int count = 0;
    sort(score.begin(), score.end(), cmp);
    
    for(int i = 0; i < score.size(); i++)
    {
        if(count < m)
        {
            count++;
            if(count >= m)
            {
                answer += score[i] * m;
                count = 0;
            }
        }

    }
    
    return answer;
}