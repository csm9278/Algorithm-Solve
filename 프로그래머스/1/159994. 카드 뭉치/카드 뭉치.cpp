#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int cardIdx1 = 0, cardIdx2 = 0;    
    bool find = false;
    
    for(int i = 0 ; i  < goal.size(); i++)
    {
        find = false;
        if(cardIdx1 < cards1.size())
        {
            
            if(goal[i] == cards1[cardIdx1])
            {
                find = true;
                cardIdx1++;
                continue;
            }
        }
        
        if(cardIdx2 < cards2.size())
        {
            if(goal[i] == cards2[cardIdx2])
            {
                find = true;
                cardIdx2++;
            }
        }
        
        if(!find)
        {
            answer = "No";
            break;
        }
    }
    return answer;
    
}