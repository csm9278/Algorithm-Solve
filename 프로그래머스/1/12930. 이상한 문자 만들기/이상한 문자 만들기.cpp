#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    
    bool makeB = true;
    cout << (char)toupper(s[0]) << " : " << (char)tolower(s[0]) << endl;
    
    for(int i = 0 ; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            makeB = true;
            continue;
        }
        
        if(makeB)
        {
            if('a' <= s[i] && s[i] <= 'z')
                s[i] += 'A' - 'a';
        }
        else
            if('A' <= s[i] && s[i] <= 'Z')
                s[i] -= 'A' - 'a';
        
        makeB = !makeB;
    }
    
    return s;
}