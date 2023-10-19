#include <string>
#include <map>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
queue<string> logInfo;
map<string, string> users;

void LogInit(string record)
{
    string s[3];
    int idx = 0;
    for(int i = 0; i < record.size(); i++)
    {
        if(record[i] == ' ')
            idx++;
        else
            s[idx] += record[i];
    }
    
    if(s[0] != "Leave")
        users[s[1]] = s[2];
    
    if(s[0] == "Change")
    {
        if(users.find(s[1]) != users.end())
            users[s[1]] = s[2];
    }
    else
    {
        logInfo.push(s[0]);
        logInfo.push(s[1]);
    }
}

vector<string> solution(vector<string> record) 
{
    vector<string> answer;
    
    for(int i = 0; i < record.size(); i++)
        LogInit(record[i]);
    
    while(!logInfo.empty())
    {
        string order = logInfo.front();
        logInfo.pop();
        string uid = logInfo.front();
        logInfo.pop();
        
        string log = "";
        if(users.find(uid) != users.end())
            log = users[uid] + "님이 ";
        
        if(order == "Enter")
            log += "들어왔습니다.";
        else if(order == "Leave")
            log += "나갔습니다.";
        
        answer.push_back(log);
    }
    
    return answer;
}