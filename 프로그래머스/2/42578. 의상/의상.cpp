#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;
    map<string, int> maps;
    
    for(int i = 0 ; i < clothes.size(); i++)
    {
        if(maps.find(clothes[i][1]) != maps.end())
        {
            maps[clothes[i][1]]++;
        }
        else
            maps[clothes[i][1]] = 1;
    }

    
    for(auto it = maps.begin(); it != maps.end(); it++)
    {
        answer *= it->second + 1;
    }
    
    
    return answer - 1;
}