#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    
    int all = brown + yellow;
    for(int height = 3; height < all; height++)
    {
        if(all % height == 0)
        {
            int weight = all / height;
            
            if((weight - 2) * (height - 2) == yellow)
            {
                answer.push_back(weight);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}