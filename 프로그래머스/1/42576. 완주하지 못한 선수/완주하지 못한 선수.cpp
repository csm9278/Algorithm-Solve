#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    
    unordered_map<string, int> partMap;
    unordered_map<string, int> completeMap;
    
    for(int i = 0 ; i < participant.size(); i++)
    {
        if(partMap.find(participant[i]) != partMap.end())
        {
            partMap[participant[i]]++;
        }
        else 
            partMap[participant[i]] = 1;
        
    }
    
    for(int i = 0 ; i < completion.size(); i++)
    {
        if(partMap.find(completion[i]) != partMap.end())
        {
            completeMap[completion[i]]++;
        }
        else 
            completeMap[completion[i]] = 1;
    }
    
    for(auto it = partMap.begin(); it != partMap.end(); it++)
    {
        if(completeMap.find(it->first) != completeMap.end())
        {
            if(it->second != completeMap[it->first])
            {
                answer = it->first;
            }
            continue;
        }
        else
        {
            answer = it->first;
            break;
        }
    }
    
    return answer;
}