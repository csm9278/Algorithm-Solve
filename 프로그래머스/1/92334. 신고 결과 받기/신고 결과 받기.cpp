#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> user;
    map<string, int> maps;
    map<pair<string, string>, int> check;
    
    for(int i = 0 ; i < report.size(); i++)
    {
        istringstream ss(report[i]);
        string a, b;
        ss >> a >> b;
        
        if(check.find(make_pair(a, b)) != check.end())
        {
            check[make_pair(a,b)]++;
            continue;
        }
        else
            check[make_pair(a,b)] = 1;
        
        if(maps.find(b) != maps.end())
            maps[b]++;
        else
            maps[b] = 1;
    }
    
    //신고 들어온 사람의 개수가 K이상일 시 -1로 변경처리
    for(auto it = maps.begin(); it != maps.end(); it++)
    {
        if(it->second >= k)
            it->second = -1;
    }
    
    //신고된 닉네임이 정지처리인지 확인
    for(int i = 0 ; i < report.size(); i++)
    {
        istringstream ss(report[i]);
        string a, b;
        ss >> a >> b;
        
        
        //-1이면 정지된 것
        if(maps[b] == -1)
        {
            if(check.find(make_pair(a,b)) != check.end())
            {
                if(check[make_pair(a,b)] > 0)
                {
                    if(user.find(a) != user.end())
                    {
                        user[a]++;
                    }
                    else
                        user[a] = 1;
                    
                    check[make_pair(a,b)] = -1;
                }
            }
            

        }
    }
    
    for(int i = 0 ; i < id_list.size(); i++)
    {
        answer.push_back(user[id_list[i]]);
    }
    
    
    return answer;
}