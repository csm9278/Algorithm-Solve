#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vecs(n);

    for(int i = 0; i < n; i++)
        cin >> vecs[i];

    sort(vecs.begin(), vecs.end(), cmp);
    int answer = vecs[0];
    for(int i = 1; i < n; i++)
    {
        if(answer < (vecs[i] * (i + 1)))
            answer = vecs[i] * (i + 1);
    }
    cout << answer;
}