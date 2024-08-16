#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans = 1;
int num;
vector<pair<int,int>> vecs;

bool cmp(pair<int, int> a, pair<int,int> b)
{
    if(a.second == b. second)
        return a.first < b.first;

    return a.second < b.second;
}

void Input()
{
    cin >> num;

    for(int i = 0; i < num; i++)
    {
        int start, end;
        cin >> start >> end;
        vecs.push_back({start, end});

    }
}

void Solve()
{
    sort(vecs.begin(), vecs.end(), cmp);

    int max, min;
    min = vecs[0].first;
    max = vecs[0].second;

    for(int i = 1; i < num; i++)
    {
        if(vecs[i].first >= max)
        {
            ans++;
            min = vecs[i].first;
            max = vecs[i].second;
        }
    }
}

int main()
{
    Input();
    Solve();
    cout << ans;
}
