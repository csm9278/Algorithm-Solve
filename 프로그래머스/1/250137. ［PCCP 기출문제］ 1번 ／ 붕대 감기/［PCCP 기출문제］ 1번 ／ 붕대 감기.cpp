#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    
    int frame = 0;
    int idx = 0;
    int combo = 0;
    while(idx < attacks.size())
    {
        frame++;
        
        if(attacks[idx][0] == frame)
        {
            answer -= attacks[idx][1];
            idx++;
            
            if(answer <= 0)
            {
                answer = -1;
                break;
            }
            combo = 0;
        }
        else
        {
            combo++;
            
            if(combo == bandage[0])
            {
                answer += (bandage[2] + bandage[1]);
                combo = 0;                
            }
            else
                answer+= bandage[1];
            
            if(answer >= health)
                answer = health;
            else if(answer <= 0)
                break;
        }
    }
    
    return answer > 0 ? answer : -1;
}