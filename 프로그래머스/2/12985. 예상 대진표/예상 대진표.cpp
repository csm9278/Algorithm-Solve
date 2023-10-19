#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    if((a % 2 == 0 && a - 1 == a ) || (b % 2 == 0 && b - 1 == a))
        return 1;
    if(a > b)
    {
        int c = a;
        a = b;
        b = c;
    }
    
    while(true)
    {
        if((a % 2 == 0 && a - 1 == a ) || (b % 2 == 0 && b - 1 == a))
            break;
        
        if(a % 2 == 0)
            a /=2;
        else
            a = (a/ 2) + 1;
        
        if(b % 2 == 0)
            b /=2;
        else
            b = (b/ 2) + 1;
        answer++;

        
    }

    return answer;
}