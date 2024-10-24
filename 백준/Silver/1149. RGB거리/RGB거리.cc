#include <iostream>
#include <vector>
using namespace std;

int dp[1001][3];

int main()
{
    int n;

    cin >> n;

    int r, g, b;
    cin >> r >> g >> b;
    dp[1][0] = r;
    dp[1][1] = g;
    dp[1][2] = b;

    for(int i = 2; i <= n; i++)
    {  
        cin >> r >> g >> b;

        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + r;
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + g;
        dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + b;
    }

    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);
    return 0;
}