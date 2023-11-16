#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> user;
vector<string> ban;

set<string> s;
bool visited[9];

bool check(string a, string b)
{
    if(a.size() != b.size()) return false;
    for(int i = 0; i < a.size(); i++) {
        if(b[i] == '*') continue;
        if(a[i] != b[i]) return false;
    }
    return true;
}

void dfs(int idx)
{
    if(idx == ban.size())
    {
        string ss = "";
        for(int i = 0 ; i < user.size(); i++)
            if(visited[i])
                ss+= user[i];
        
        s.insert(ss);
        return;
    }
    
    for(int i = 0 ; i < user.size(); i++)
    {
        if(visited[i])
            continue;
        
        if(check(user[i], ban[idx]))
        {
            visited[i] = true;
            dfs(idx + 1);
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    user = user_id;
    ban = banned_id;    
    dfs(0);
    return s.size();
}