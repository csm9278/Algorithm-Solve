#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

int n, m;
vector<vector<int>> vecs;
bool visited[101] = {false};
int target, target2;
int answer = INT_MAX;
void Input()
{
    cin >> n;
    vecs.resize(n + 1);
    cin >> target >> target2 >> m;

    for(int i = 0; i < m; i++)
    {
        int first, second;
        cin >> first >> second;

        vecs[first].push_back(second);
        vecs[second].push_back(first);
    }
}

void DFS(int num, int count)
{

    if(num == target2)
    {
        answer = min(answer, count);
        return;
    }

    for(int i = 0; i < vecs[num].size(); i++)
    {
        if(!visited[vecs[num][i]])
        {
            visited[vecs[num][i]] = true;
            DFS(vecs[num][i], count + 1);
        }
    }
}

void Solve()
{
    visited[target] = true;
    DFS(target, 0);
}

int main()
{
    Input();
    Solve();

    if(answer == INT_MAX)
        cout <<-1;
    else
        cout << answer;
    return 0;
}