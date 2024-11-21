#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001] = {0};
int dp[1001];
int n;

void Input()
{
    cin >> n;
    fill(dp, dp + 1001, 1);

    for(int i = 0; i < n; i++)
        cin >> arr[i];
}

void Solve()
{
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);

    cout << *max_element(dp, dp + 1001) << endl;
}


int main()
{
    Input();
    Solve();

    return 0;
}