#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int minNum = routes[0][1];
    for(int i = 1 ; i < routes.size(); i++)
    {
        if(minNum < routes[i][0])
        {
            answer++;
            minNum = routes[i][1];
        }
        
        if (minNum >= routes[i][1])    minNum = routes[i][1];
    }
    
    return answer;
}