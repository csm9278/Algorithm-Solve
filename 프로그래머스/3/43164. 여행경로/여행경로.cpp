#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool visit[10001] = {false};
vector<vector<string>> tk;
vector<string> answer;

bool find(string now, int count)
{
    if(count == tk.size())
    {
        return true;
    }
    
    for(int i = 0 ; i < tk.size(); i++)
    {
        cout << now << " : " << tk[i][0] << endl;
        if(now == tk[i][0] && !visit[i])
        {
            visit[i] = true;
            answer.push_back(tk[i][1]);
            cout << tk[i][1] << endl;
            bool res = find(tk[i][1], count + 1);
            visit[i] = false;
            
            if(res)
                return true;
        }
    }
    
    answer.pop_back();
    return false;

}

vector<string> solution(vector<vector<string>> tickets) 
{
    sort(tickets.begin(), tickets.end());
    tk = tickets;
    answer.push_back("ICN");
    find("ICN", 0);
    
    return answer;
}