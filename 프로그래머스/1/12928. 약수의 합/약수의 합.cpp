#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = n;
    
    for(int i = 1; i <= n/2; i++)
    {
        if(n % i == 0)
        {
            answer += i;
            cout << i << endl;            
        }
    }
    return answer;
}