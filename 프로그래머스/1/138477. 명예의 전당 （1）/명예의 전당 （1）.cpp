#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> ques;
    
    for(int i = 0 ; i < score.size(); i++)
    {
        if(ques.size() < k)
        {
            ques.push(score[i]);
            answer.push_back(ques.top());
        }
        else
        {
            if(ques.top() < score[i])
            {
                ques.pop();
                ques.push(score[i]);
                answer.push_back(ques.top());
            }
            else
                answer.push_back(ques.top());
        }
    }
    
    
    return answer;
}