#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int n;
    cin >> n;

    vector<int> vecs(n);
    for(int i = 0; i < n; i++)
        cin >> vecs[i];


    sort(vecs.begin(), vecs.end());

    int answer = vecs[0];
    for(int i = 1 ; i < vecs.size(); i++)
    {
        vecs[i] = vecs[i] + vecs[i - 1];
        answer += vecs[i];
    }
    
    cout << answer;
    return 0;
}