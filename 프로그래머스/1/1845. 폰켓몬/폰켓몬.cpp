#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    map<int, int> mons;
    map<int, int> combine;
    int getNums = nums.size() / 2;
    int kind = 0;
    
    for(int i = 0 ; i < nums.size(); i++)
    {
        if(mons.find(nums[i]) != mons.end())
        {
            mons[nums[i]]++;
        }
        else
            mons[nums[i]] = 1;
    }
    
    if(mons.size() >= getNums)
        answer = getNums;
    else
        answer = mons.size();
    
    return answer;
}