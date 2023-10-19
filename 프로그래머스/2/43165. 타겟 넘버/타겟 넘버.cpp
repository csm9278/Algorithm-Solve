#include <string>
#include <queue>
#include <vector>

using namespace std;


int solution(vector<int> numbers, int target) 
{
    int answer = 0;
    queue<pair<int, int>> que;
    int numSize = numbers.size();
    
    que.push(make_pair(0, numbers[0]));
    que.push(make_pair(0, numbers[0] * -1));
    
    while (!que.empty())
    {
        int idx = que.front().first;
        int number = que.front().second;
        que.pop();

        if (idx + 1 < numSize)
        {
            for (int i = 0; i < 2; i++)
            {
                if(i == 0)
                    que.push(make_pair(idx + 1, number + (numbers[idx + 1])));
                else
                    que.push(make_pair(idx + 1, number + (numbers[idx + 1] * -1)));
            }
        }
        else
        {
            if (number == target)
                answer++;
        }
    }
    
    return answer;
}