#include <string>
#include <vector>
#include <iostream>

using namespace std;
int w[200022] = {0};

long long solution(int n, vector<int> works) 
{
    long long answer = 0;

    int maxIdx = 0;
    
    for(int i = 0; i < works.size(); i++)
    {
        w[works[i]]++;
        
        maxIdx = max(works[i], maxIdx);
    }
    
    while(n > 0)
    {
        if(w[maxIdx] > 0)
        {
            w[maxIdx]--;
            w[maxIdx - 1]++;
            n--;
        }
        if(w[maxIdx] <= 0)
            maxIdx--;
    }
    if(maxIdx <= 0)
        answer = 0;
    else
    {
        while(maxIdx > 0)
        {
            if(w[maxIdx] > 0)
            {
                answer += (maxIdx * maxIdx);
                w[maxIdx]--;
            }
            
            if(w[maxIdx] <= 0)
                maxIdx--;
        }
    }
        
    return answer;
}