#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    
    int idx = 0;
    while(budget > 0)
    {
        budget -= d[idx];
        if(budget >= 0)
        {
            answer++;
            idx++;
        }
    }
    
    return answer > d.size() ? d.size() : answer;
}