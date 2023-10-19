#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string s = to_string(x);
    
    int num = 0;
    for(int i = 0; i < s.size(); i++)
        num += s[i] - '0';
    
    if(x % num != 0)
        answer = false;
    
    return answer;
}