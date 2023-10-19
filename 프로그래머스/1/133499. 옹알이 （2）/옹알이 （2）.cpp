#include <string>
#include <vector>

using namespace std;

string s[] = {"aya", "woo", "ye", "ma"};
int sint[] = {3, 3, 2, 2};

int solution(vector<string> babbling) {
    int answer = 0;
    for(int i = 0; i < babbling.size(); i++)
    {
        int before = -1;
        
        while(true)
        {
            bool del = false;
            
            for(int j = 0; j < 4; j++)
            {
                if(babbling[i].size() < sint[j] || before == j)
                    continue;
                
                string cmp = babbling[i].substr(0,sint[j]);
                if(cmp == s[j])
                {
                    babbling[i].erase(0, sint[j]);
                    before = j;
                    del = true;
                    break;
                }
            }
            
            if(babbling[i] == "")
            {
                answer++;
                break;
            }
            
            if(!del)
                break;
        }
    }
    
    return answer;
}