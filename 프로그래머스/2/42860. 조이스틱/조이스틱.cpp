#include <string>
#include <vector>

using namespace std;

int ChangeAlpha(char target)
{
    int a = 0, b = 0;
    a = (target - 'A');
    
    b = ('Z' - target) + 1;
    
    return min(a, b);
}

int solution(string name) {
    int answer = 0;
    int n = name.length();
    int turn = n - 1; 
    
    for(int i = 0 ; i < n; i++)
    {
        answer += ChangeAlpha(name[i]);
        
        int ind = i + 1;
        while (ind < n && name[ind] == 'A') ind++;

        turn = min(turn, i + n - ind + min(i, n - ind));
        
    }
    
    answer += turn;
    
    
    return answer;
}