#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    bool haveTarget = false;
    for(int i = 0; i < words.size(); i++)
    {
        if(words[i] == target)
        {
            haveTarget = true;
            break;            
        }
    }
    if(!haveTarget)
        return 0;
    
    queue<pair<string, int>> ques;
    
    ques.push({begin, 0});
    
    while(!ques.empty())
    {
        string now = ques.front().first;
        int count = ques.front().second;
        ques.pop();
        
        if(now == target)
        {
            answer = count;
            break;
        }
        //같은 수 비교
        for(int i = 0; i < words.size(); i++)
        {
            int same = 0;
            
            for(int j = 0; j < now.size(); j++)
                if(words[i][j] == now[j])
                    same++;
            if(same == now.size() - 1)
            {
                ques.push({words[i], count+1});
            }
        }
    }
    
    return answer;
}