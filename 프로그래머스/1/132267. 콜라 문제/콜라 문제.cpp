#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int add = 0;
    
    while(true)
    {
        int getCoke = n / a;

        int add = n % a;
        n = (n / a) * b;
        n += add;
        if(getCoke == 0)
            break;
        
        answer += getCoke * b;
    }
    
    return answer;
}