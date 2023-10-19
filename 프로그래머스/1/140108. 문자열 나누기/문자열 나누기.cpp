#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    map<char,int> maps;
    char x = 'A';
    int xCount = 0, other = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(x == 'A')
        {
            x = s[i];
            xCount = 1;
        }
        else
        {
            if(s[i] == x)
            {
                xCount++;
            }
            else
            {
                other++;
                if(xCount == other)
                {
                    answer++;
                    xCount = 0;
                    other = 0;
                    x = 'A';
                }
            }
        }
    }
    
    if(x != 'A')
        answer++;
    
    return answer;
}