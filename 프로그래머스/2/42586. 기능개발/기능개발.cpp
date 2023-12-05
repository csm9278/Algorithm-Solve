#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 0;
    int count = -1;

    for(int i = 0; i < progresses.size(); i++)
    {
        if(progresses[i] + (speeds[i] * day) < 100)
        {
            progresses[i] += (speeds[i] * day);
            while(progresses[i] < 100)
            {
                progresses[i] += speeds[i];
                day++;
            }
            answer.push_back(1);
            count++;
        }
        else
            answer[count]++;
    }

    return answer;
}