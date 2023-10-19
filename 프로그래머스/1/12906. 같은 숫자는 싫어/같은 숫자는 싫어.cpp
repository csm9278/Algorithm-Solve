#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> ques;
    
    ques.push(arr[0]);
    for(int i = 1; i < arr.size(); i++)
    {
        if(ques.back() != arr[i] )
            ques.push(arr[i]);
    }
    
    while(ques.size() > 0)
    {
        answer.push_back(ques.front());
        ques.pop();
    }



    return answer;
}