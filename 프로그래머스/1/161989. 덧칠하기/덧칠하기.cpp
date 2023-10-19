#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    int now = section[0];
    
    if(m == 1)
        return section.size();
    
    for(int i = 1; i < section.size(); i++)
    {
        if(m - (section[i] - now) <= 0)
        {
            now = section[i];
            answer++;
        }
    }
    
    return answer;
}