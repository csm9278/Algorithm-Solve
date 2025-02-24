#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
int kayak[10] = {0};
vector<int> scoreList;

bool cmp(int a, int b)
{
    return a > b;
}

void Solve()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 1; j < m; j++)
        {
            if(s[j] != '.' && s[j] != 'F')
            {
                int num = s[j] - '0';
                kayak[num] = j + 2;
                scoreList.push_back(j + 2);
                break;
            }
        }
    }

    sort(scoreList.begin(), scoreList.end(), cmp);
    scoreList.erase(unique(scoreList.begin(), scoreList.end()), scoreList.end());

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < scoreList.size(); j++)
        {
            if(kayak[i] == scoreList[j])
                cout << j + 1 << endl;
        }
    }

}


int main()
{
    Solve();
    return 0;
}