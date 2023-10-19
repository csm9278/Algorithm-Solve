#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<string, int> p;
    
    for(int i = 0; i < players.size(); i++)
    {
        p[players[i]] = i;
    }
    
    for(int i = 0; i < callings.size(); i++)
    {
        int rate = p[callings[i]];
        //추월당한 선수이름
        string pname = players[rate - 1];
        
        players[rate - 1] = callings[i]; 
        players[rate] = pname;
        p[callings[i]] --;
        p[pname]++;
    }
    
    for(int i = 0; i < players.size(); i++)
    {
        answer.push_back(players[i]);
    }
    
    
    
    return answer;
}