#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> maps;
    
    string s = "";
    char al = 'A';
    s += al;
    for(int i = 1 ; i <= 26; i++)
    {
        maps[s] = i;
        al++;
        s = "";
        s += al;
    }
    
    s = "";
    int dicNum = 27;
    for(int i = 0 ; i < msg.size(); i++)
    {
        s += msg[i];
        
        for(int j = i + 1 ; j < msg.size(); j++)
        {
            s += msg[j];
            if(maps.find(s) == maps.end())
            {
                maps[s] = dicNum;
                dicNum++;
                
                s.erase(s.end() - 1);
                if(maps.find(s) != maps.end())
                    answer.push_back(maps[s]);

                i += j-1 - i;
                s = "";
                
                break;
            }
        }
        
        if(s != "")
        {
            answer.push_back(maps[s]);
            break;
        }
    }
    

    
    return answer;
}