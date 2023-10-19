#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    map<char, int> maps;
    for(int i = 0 ; i < skill.size(); i++)
    {
        maps[skill[i]] = i;
    }
    
    for(int i = 0 ; i < skill_trees.size(); i++)
    {
        int learn = 0;
        for(int j = 0; j < skill_trees[i].size(); j++)
        {
            if(maps.find(skill_trees[i][j]) != maps.end())
            {
                if(maps[skill_trees[i][j]] > learn)
                {
                    answer--;
                    break;
                }
                else
                    learn++;
            }
        }
    }
    
    
    return answer;
}