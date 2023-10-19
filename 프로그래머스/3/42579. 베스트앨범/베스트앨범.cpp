#include <string>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;
    
    map<string, int> music;
    map<string, map<int, int>> musicList;
    
    for(int i = 0 ; i < genres.size(); i++)
    {
        music[genres[i]] += plays[i];
        musicList[genres[i]][i] = plays[i];
    }
    
    while(music.size() > 0)
    {
        string bestName = "";
        int bestPlay = 0;
        
        for(auto mu : music)
        {
            if(mu.second > bestPlay)
            {
                bestPlay = mu.second;
                bestName = mu.first;
            }
        }
        
        for(int i = 0; i < 2; i++)
        {
            int val = 0; int idx = -1;
            for(auto m1 : musicList[bestName])
            {
                if(val < m1.second)
                {
                    val = m1.second;
                    idx = m1.first;
                }
            }
            
            if(idx == -1)
                break;
            
            answer.push_back(idx);
            musicList[bestName].erase(idx);
        }
        
        music.erase(bestName);
    }

    
    return answer;
}