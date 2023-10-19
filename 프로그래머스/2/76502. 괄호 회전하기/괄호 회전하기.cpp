#include <string>
#include <vector>
#include <queue>

using namespace std;

char open[] = { '[', '(', '{'};
char close[] = { ']', ')', '}'};
int Check[3] = {0};

int solution(string s) {
    int answer = 0;
    queue<int> stacks;
    queue<int> compStacks;
    int openCount = 0;
    bool opening = false;
    int openDoor = -1;
    
    for(int i = 0 ; i < s.size(); i++)
    {
        for(int j = 0 ; j < 3; j++)
        {
            if(s[i] == open[j])
            {
                stacks.push(j + 1);
            }
            else if(s[i] == close[j])
            {
                stacks.push(-1 * (j + 1));
            }
        }
    }
    compStacks = stacks;
    int compare = 0;
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = 0 ; j < s.size(); j++)
        {
            int number = compStacks.front();
            compare += number;
            
            if(number > 0)
            {
                if(opening == false)
                {
                    openDoor = number - 1;
                    opening = true;
                }
                
                Check[number - 1]++;
                openCount++;
            }
            else
            {
                Check[(-number) - 1]--;
                openCount --;
                
                if(((-number) - 1) == openDoor && Check[(-number) - 1] == 0)
                {
                    opening = false;
                    openDoor = -1;
                }
                
                if(Check[(-number) - 1] == 0 && opening == false)
                {
                    if(openCount > 0)
                    {
                        if(Check[0] > 0 || Check[1] > 0 || Check[2] > 0)
                        {
                            compare = -1;
                            break;
                        }
                    }
                }
                

                
                if(Check[(-number) - 1] < 0)
                {
                    compare = -1;
                    break;
                }
            }
            compStacks.pop();
        }
        Check[0] = 0;
        Check[1] = 0;
        Check[2] = 0;
        
        if(compare >= 0 && openCount == 0 && opening == false)
            answer++;
        compare = 0;
        openCount =0;
        int a = stacks.front();
        stacks.push(a);
        stacks.pop();
        compStacks = stacks;
    }
    
    return answer;
}