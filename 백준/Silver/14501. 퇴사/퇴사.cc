#include <iostream>
using namespace std;

int dp[16];
int answer = 0;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i <= n; i++)
    {
        int day, pay;
        cin >> day >> pay;

        if(i + day - 1 > n)
            continue;     

        for(int j = i + day; j <= n; j++)
        {
            dp[j] = max(dp[j], dp[i] + pay);
        }

        answer = max(dp[i + day], answer);
    }

    cout << answer;

    return 0;
}