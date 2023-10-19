#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> maps;
    map<string, int> curMap;
    
    for(int i = 0 ; i < want.size(); i++)
    {
        maps[want[i]] = number[i];
    }
    curMap = maps;
    
    for(int i = 0 ; i <= discount.size() - 10; i++)
    {
        for(int j = i ; j < 10 + i; j++)
        {
            if(curMap.find(discount[j]) != curMap.end())
            {
                curMap[discount[j]]--;
                if(curMap[discount[j]] <= 0)
                {
                    curMap.erase(discount[j]);
                }
            }
            else
                break;
        }
        
        if(curMap.size() <= 0)
            answer++;
        
        curMap = maps;
    }
    
    
    return answer;
}