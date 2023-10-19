#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) 
{
    vector<int> answer;
    
    if(n > s)
    {
        answer.push_back(-1);
        return answer;
    }
    
    for(int i = n ; i > 1; i--)
    {
        int a = s / i;
        answer.push_back(a);
        s -= a;
    }
    answer.push_back(s);
    
    return answer;
}