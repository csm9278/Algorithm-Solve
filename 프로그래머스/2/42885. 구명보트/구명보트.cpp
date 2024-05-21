#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 1;
    int boat = 0;
    int max = 0;
    sort(people.begin(), people.end());
    
    for(int i = 0; i < people.size(); i++)
    {
        if(people[i] + boat <= limit && max < 2)
        {
            boat += people[i];
            max++;
        }
        else
        {
            answer++;
            max = 0;
            boat = 0;
            boat += people[i];
            max++;
        }
        
    }
    
    return answer;
}