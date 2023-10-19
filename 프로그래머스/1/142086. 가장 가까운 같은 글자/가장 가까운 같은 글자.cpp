#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char,int> maps;

    for(int i = 0 ; i < s.size(); i++)
    {
        if(maps.find(s[i]) != maps.end())
        {
            answer.push_back(i - maps[s[i]]);
            maps[s[i]] = i;
        }
        else
        {
            maps[s[i]] = i;
            answer.push_back(-1);
        }
    }
    return answer;
}