#include <iostream>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> comps;
bool visited[101] = {false};
int answer = 0;

void Input()
{
    cin >> n >> m;
    comps.resize(n + 1);

    for(int i =0; i < m; i++)
    {
        int first, second;

        cin >> first >> second;

        comps[first].push_back(second);
        comps[second].push_back(first);
    }
}

void Solve()
{
    queue<int> ques;

    ques.push(1);
    visited[1] = true;

    while(!ques.empty())
    {
        int comNum = ques.front();
        ques.pop();

        for(int i = 0; i < comps[comNum].size(); i++)
        {
            if(!visited[comps[comNum][i]])
            {
                ques.push(comps[comNum][i]);
                visited[comps[comNum][i]] = true;
                answer++;
            }

        }

    }
}

int main()
{
    Input();
    Solve();

    cout << answer;
    return 0;
}