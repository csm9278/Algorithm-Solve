#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
map<int, int> maps;
map<int, int> paymaps;
priority_queue<int> que;

void CheckTime(string str)
{
    int time = ((stoi(str.substr(0, 2)) * 60) + (stoi(str.substr(3, 2))));
    int carNum = (stoi(str.substr(6, 4)));
    string inOut = str.substr(11, 1);
    
    if(inOut == "I")
    {
        maps[carNum] = time;
    }
    else
    {
        int priceTime = time - maps[carNum];
        paymaps[carNum] += priceTime;
        maps.erase(carNum);
    }
}
///

///
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    for(int i = 0; i < records.size(); i++)
    {
        CheckTime(records[i]);
    }
    
    for(auto m : maps)
    {
        int priceTime = 1439 - m.second;
        paymaps[m.first] += priceTime;
    }
    for(auto m : paymaps)
    {
        que.push(m.first);
    }
    
    while(!que.empty())
    {
        int i = que.top();
        que.pop();
        
        cout << paymaps[i] << endl;
        if(paymaps[i] <= fees[0])
            answer.push_back(fees[1]);
        else
        {
            int p = fees[1] + (((paymaps[i] - fees[0]) / fees[2]) * fees[3]);
            if(((paymaps[i] - fees[0]) % fees[2]) != 0)
                p += fees[3];
            answer.push_back(p);
        }
    }
      
    reverse(answer.begin(), answer.end());
    return answer;
}