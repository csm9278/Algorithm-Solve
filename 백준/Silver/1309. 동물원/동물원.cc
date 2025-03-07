#include <iostream>
using namespace std;

#define REM 9901
int n;
int dp[100001][3];


int main()
{
    cin >> n;
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % REM;
        dp[i][1] = (dp[i-1][0] + dp[i - 1][2]) % REM;
        dp[i][2] = (dp[i-1][0] + dp[i - 1][1]) % REM;
    }

    cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % REM;

    return 0;
}