#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0)
        return cities.size() * 5;
    
    deque<string> dq;
    
    for(int i = 0; i < cities.size(); i++)
    {
        bool hit = false;
        
        string cache = cities[i];
        
        for (int j = 0; j < cache.length(); j++)
            cache[j] = tolower(cache[j]);
        
        for(int j = 0; j < dq.size(); j++)
        {
            if(cache == dq[j])
            {
                hit = true;
                dq.erase(dq.begin() + j);
            }
        }
        dq.push_back(cache);
        
        if(hit)
            answer++;
        else
            answer += 5;
        
        if(dq.size() > cacheSize)
            dq.pop_front();
    }
    
    return answer;
}