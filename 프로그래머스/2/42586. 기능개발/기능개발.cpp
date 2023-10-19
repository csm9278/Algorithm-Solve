#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    
    int days = 0;
    int count = 0;
    while(progresses.size() > 0)
    {   
        for(int i = 0 ; i < progresses.size(); i++)
        {
            if(progresses[i] + (speeds[i] * days) >= 100)
            {
                count++;
            }
            else
                break;
        }
        days++;
        
        if(count > 0)
        {
            answer.push_back(count);
            progresses.erase(progresses.begin(), progresses.begin() + count);
            speeds.erase(speeds.begin(), speeds.begin() + count);
            count = 0;
        }
    }
    
    return answer;
}