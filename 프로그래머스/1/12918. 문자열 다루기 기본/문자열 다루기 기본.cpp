#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;

    if(4 != s.size() && s.size() != 6)
        return false;
    
    for(int i = 0 ; i < s.size(); i++)
        if(('a' <= s[i] && s[i] <= 'z') ||
          ('A' <= s[i] && s[i] <= 'Z'))
            answer = false;

    return answer;
}