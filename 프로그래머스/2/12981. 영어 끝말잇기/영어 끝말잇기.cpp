#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    vector<int> answer;
    map<string, int> maps;
    bool find = false;
    int pCount = 1, nCount = 1;
    
    for(int i = 0 ; i < words.size() - 1; i++)
    {
        find = false;
        if(words[i][words[i].size() - 1] == words[i + 1][0]
          &&maps.find(words[i + 1]) == maps.end())
        {
                maps[words[i]] = 1;
        }
        else
        {
            find = true;
            for(int j = i; j < words.size() - 1; j++)
            {
                if(words[i][words[i].size() - 1] == words[i + 1][0]
                    &&maps.find(words[i + 1]) == maps.end())
                {
                    maps[words[i]] = 1;
                    find = false;
                }   
            } 
        }
        nCount++;
        if(nCount > n)
        {
            nCount = 1;
            pCount++;            
        }
        
        if(find)
            break;
    }
    
    if(nCount * pCount == words.size() && !find)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(nCount);
        answer.push_back(pCount);
    }
    return answer;
}