#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int TimeStrToInt(string s)
{
    string time;
    time += s[0];
    time += s[1];
    time += s[3];
    time += s[4];
    return stoi(time);
}

int TransTime(int time)
{
    if(time % 100 > 59)
    {
        time += 40;
    }
    return time;
}



int solution(vector<vector<string>> book_time) 
{
    int answer = 1;
    
    vector<int> outVec;
    sort(book_time.begin(), book_time.end());
    outVec.push_back(TransTime(TimeStrToInt(book_time[0][1]) + 10));
    
    for(int i = 1; i < book_time.size(); i++)
    {
        int nextInput = 0;
        nextInput = TimeStrToInt(book_time[i][0]);
        
        bool addRoom = true;
        for(int j = 0; j < outVec.size(); j++)
        {
            if(outVec[j] <= nextInput)
            {
                outVec[j] = TransTime(TimeStrToInt(book_time[i][1]) + 10);
                addRoom = false;
                break;
            }
        }
        
        if(addRoom)
        {
            answer++;
            outVec.push_back(TransTime(TimeStrToInt(book_time[i][1]) + 10));
        }
    }
    return answer;
}