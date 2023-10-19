#include <string>
#include <queue>
#include <vector>

using namespace std;


long nums[2001] = {0};


long long solution(int n) 
{
    long long answer = 0;
    
    nums[1] = 1;
    nums[2] = 2;
    
    for(int i = 3 ; i <= n; i++)
    {
        nums[i] = (nums[i - 1] + nums[i - 2]) % 1234567;
    }
    

    return nums[n];
}