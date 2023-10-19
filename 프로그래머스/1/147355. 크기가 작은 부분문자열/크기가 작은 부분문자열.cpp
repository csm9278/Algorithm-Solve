#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    vector<unsigned long long> vecs;
    for(int i = 0 ; i <= t.size() - p.size(); i++)
    {
        unsigned long long num = stoull(t.substr(i, p.size()));
        
        vecs.push_back(num);
    }
    
    unsigned long long pNum = stoull(p);
    for(int i = 0 ; i < vecs.size(); i++)
    {
        if(vecs[i] <= pNum)
            answer++;
    }
    
    return answer;
}