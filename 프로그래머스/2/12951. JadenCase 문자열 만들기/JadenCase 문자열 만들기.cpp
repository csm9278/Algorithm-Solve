#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if('a' <= s[0] && s[0] <= 'z')
    {
        s[0] -= 32;
        answer += s[0];          
    }
    else
        answer+= s[0];
    
    for(int i = 1 ; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            
            if('a' <= s[i + 1] && s[i + 1] <= 'z')
            {
                s[i + 1] -= 32;
                answer += s[i];
                answer += s[i + 1];   
                i++;
            }
            else
            {
                if('A' <= s[i + 1] && s[i + 1] <= 'Z')
                {
                    answer += s[i];
                    answer += s[i + 1];   
                    i++;
                    continue;
                }
                answer += s[i];

            }
            continue;
        }
        
        if('A' <= s[i] && s[i] <= 'Z')
        {
            s[i] += 32;
            answer += s[i];   
            continue;
        }
        
        answer += s[i];
    }
    
    
    
    return answer;
}