#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string num = "";
    unordered_map<int, string> maps;
    unordered_map<int, int> ansmap;
    int slash = 0;
    for(int i =0; i < s.size(); i++)
    {
        if(isdigit(s[i]))
        {
            while(s[i] != '}')
            {
                if(s[i] == ',')
                    slash++;
                num += s[i];
                i++;
            }
            maps[slash] = num; 
            num = "";
            slash = 0;
        }
    }
    
    int idx = 0;
    while(idx < maps.size())
    {
        for(int i = 0 ; i < maps[idx].size(); i++)
        {
            if(isdigit(maps[idx][i]))
                num += maps[idx][i];
            else
                if(num != "")
                {
                    int snum = stoi(num);
                    if(ansmap.find(snum) == ansmap.end())
                    {
                        ansmap[snum] = 1;
                        answer.push_back(snum);
                    }
                    num = "";
                }
        }
        
        if(num != "")
        {
            int snum = stoi(num);
            if(ansmap.find(snum) == ansmap.end())
            {
                ansmap[snum] = 1;
                answer.push_back(snum);
            }
            num = "";
        }
        
        idx++;
    }
    return answer;
}