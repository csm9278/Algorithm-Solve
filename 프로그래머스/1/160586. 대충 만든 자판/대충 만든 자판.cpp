#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<map<char,int>> maps;
    
    for(int i = 0; i < keymap.size(); i++)
    {
        map<char, int> m;
        for(int j = 0; j < keymap[i].size(); j++)
        {
            m.insert({keymap[i][j], j + 1});
        }
        
        maps.push_back(m);
    }
    
    for(int i = 0 ; i < targets.size(); i++)
    {
        int minNum = 101;
        int sum = 0;
        bool bPass = false;
        for(int j = 0; j < targets[i].size(); j++)
        {
            for(int k = 0; k < maps.size(); k++)
            {
                if(maps[k].find(targets[i][j]) != maps[k].end())
                {
                    minNum = min(minNum, maps[k][targets[i][j]]);
                }
                
            }
            
            if(minNum == 101)
            {
                bPass = true;
                answer.push_back(-1);
                break;
            }
            else
            {
                sum += minNum;
                minNum = 101;
            }
            
        }
        
        if(!bPass)
            answer.push_back(sum);
    }
    
    return answer;
}