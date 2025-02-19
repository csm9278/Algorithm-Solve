#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, m;
map<string, string> maps;

void Input()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        string site;
        string pw;

        cin >> site >> pw;

        maps[site] = pw;
    }
}

void Solve()
{
    for(int i = 0; i < m; i++)
    {
        string site;
        cin >> site;

        if(maps.find(site) != maps.end())
            cout << maps[site] << "\n";
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Input();
    Solve();
     
    return 0;


}