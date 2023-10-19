#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int getParent(vector<int> vecs, int target)
{
    if(vecs[target] == target) return target;
    else return getParent(vecs, vecs[target]);
}

void Connect(vector<int>& vecs, int first, int second)
{
    int a = getParent(vecs, first);
    int b = getParent(vecs, second);
    
    if(a > b) vecs[a] = b;
    else    vecs[b] = a;
}

bool isConnect(vector<int> vecs, int first, int second)
{
    int a = getParent(vecs, first);
    int b = getParent(vecs, second);
    
    if(a == b) return true;
    else return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), cmp);
    
    vector<int> con(n);
    
    for(int i = 0 ; i < con.size(); i++)
        con[i] = i;
    
    for(int i = 0; i < costs.size(); i++)
    {
        if(!isConnect(con, costs[i][0], costs[i][1]))
        {
            Connect(con, costs[i][0], costs[i][1]);
            answer += costs[i][2];
        }
        
    }
    
    return answer;
}