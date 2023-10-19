#include <string>
#include <vector>
#include <iostream>

using namespace std;

int vec[10000000] = {0};


int solution(int n) 
{
    int answer = 0;
    
    vec[0] = 0;
    vec[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        vec[i] = vec[i - 1] + vec[i - 2];
        vec[i] %= 1234567;
    }
    
    return vec[n];
}