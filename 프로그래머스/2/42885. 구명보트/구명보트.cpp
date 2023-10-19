#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) 
{
    if(people.size() == 1)
        return 1;

    int answer = 0;
    int idx = 0;
    sort(people.begin(), people.end());
    
    
    while(people.size() > idx)
    {
        if(people[idx] + people[people.size() - 1] <= limit)
        {
            answer++;
            idx++;
            people.pop_back();
        }
        else
        {
            answer++;
            people.pop_back();
        }
        
    }
    
    
    return answer;
}