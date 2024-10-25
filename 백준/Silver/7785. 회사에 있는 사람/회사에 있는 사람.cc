#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string,int> a, pair<string,int> b)
{
    return a.first > b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    unordered_map<string, int> maps;

    while(n--)
    {
        string name, enter;
        cin >> name >> enter;

        if(enter == "enter")
            maps[name] = 1;
        else
            maps.erase(name);
    }   

    vector<pair<string,int>> vecs(maps.begin(), maps.end());
    sort(vecs.begin(), vecs.end(), cmp);

    for(int i = 0; i < vecs.size(); i++)
        cout << vecs[i].first << '\n';

}