#include <string>
#include <cmath>
#include <queue>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    queue<int> ques;
    
    for(int i= 0; i < dartResult.size(); i++)
    {
        if(isdigit(dartResult[i]))
        {
            int num = dartResult[i] - '0';
            int idx = 1;
            if(isdigit(dartResult[i + idx]))
            {
                num = 10;
                idx++;
            }
            if(dartResult[i+idx] == 'S')
            {
                num = pow(num, 1);
                ques.push(num);
            }
            else if(dartResult[i + idx] == 'D')
            {
                num = pow(num, 2);
                ques.push(num);
            }
            else if(dartResult[i + idx] == 'T')
            {
                num = pow(num, 3);
                ques.push(num);
            }
            
            if(ques.size() > 2)
            {
                answer += ques.front();
                ques.pop();
            }
            i++;
        }
        else
        {
            if(dartResult[i] == '*')
            {
                if(ques.size() > 1)
                {
                    ques.front() *= 2;
                    ques.back() *= 2;
                }
                else
                    ques.front() *= 2;
            }
            else if(dartResult[i] == '#')
                ques.back() *= -1;
        }
    }
    
    while(!ques.empty())
    {
        answer += ques.front();
        ques.pop();
    }
    
    
    return answer;
}