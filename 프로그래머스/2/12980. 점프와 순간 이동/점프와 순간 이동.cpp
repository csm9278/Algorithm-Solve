#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    if(n == 1)
        return 1;
    while(n >= 1)
    {
        if(n%2 == 0)
            n /= 2;
        else
        {
            ans++;
            n /= 2;            
        }
    }

    return ans;
}