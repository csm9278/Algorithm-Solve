#include <iostream>
#include <map>
#include <vector>;
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string,int> b)
{
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;  
    map<string, int> maps;

    for(int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        maps[s] = i;

    }

    vector<pair<string,int>> vecs(maps.begin(), maps.end());
    sort(vecs.begin(), vecs.end(), cmp);

    for(int i = 0 ; i < vecs.size(); i++)
    {
        n--;

        cout << vecs[i].first << '\n';

        if(n <= 0)
        break;
    }

    return 0;
}