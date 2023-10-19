#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    map<char, int> maps;
    
    for(int i = 0; i < skip.size(); i++)
    {
        maps[skip[i]] = i;
    }
    
    for(int i = 0 ; i < s.size(); i++)
    {
        int c = (int)s[i];
        for(int j = 0; j < index; j++)
        {
            while(true)
            {
                c++;
                if(c > 122)
                    c-=26;
                if(maps.find((char)c) == maps.end())
                    break;                
            }

        }
        answer+= (char)c;
    }
    
    
    
    return answer;
}