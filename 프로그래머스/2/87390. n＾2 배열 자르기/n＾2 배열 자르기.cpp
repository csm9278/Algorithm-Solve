#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    int startY = 0, startX = 0;
    int count = right - left + 1;
    startY = left / n;
    startX = left % n;
    
    while(count > 0)
    {
        answer.push_back(max(startY + 1, startX + 1));
        startX++;
        if(startX >= n)
        {
            startX = 0;
            startY++;
        }
        
        count--;
    }
    
    return answer;
}