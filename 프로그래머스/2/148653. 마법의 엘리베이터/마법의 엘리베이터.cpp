#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int storey) 
{
    int answer = 0;
    int answer2 = 0;
    
    int testSt = storey;
    while(testSt > 0)
    {
        int res = testSt % 10;
        
        if(res < 6)
            answer2 += res;
        else
        {
            answer2 += (10 - res);
            testSt += 10;
        }
        
            testSt /= 10;
    }
    
    while(storey > 0)
    {
        int res = storey % 10;
        
        if(res < 5)
            answer += res;
        else
        {
            answer += (10 - res);
            storey += 10;
        }
        
            storey /= 10;
    }
    
    return min(answer, answer2);
}