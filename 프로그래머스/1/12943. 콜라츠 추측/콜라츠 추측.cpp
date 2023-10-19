#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    int count = 0;
    long long num2 = num;
    
    if(num == 1)
        return 0;
    
    while(count < 500)
    {
        if(num2 % 2 == 0)
            num2 /= 2;            
        else
            num2 = (num2 * 3) + 1;
        
        count++;
        
        if(num2 == 1)
            return count;
    }
    
    return -1;
}