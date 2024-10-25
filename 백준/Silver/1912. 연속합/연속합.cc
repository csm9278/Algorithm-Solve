#include <iostream>
using namespace std;

int dp[100001];
int answer = 0;

int main()
{
    int n;
    cin >> n;

    int num;
    cin >> num;
    dp[0] = num;
    answer = dp[0];

    for(int i = 1; i < n; i++)
    {
        cin >> num;
        dp[i] = max(num, dp[i-1] + num);
        answer = max(answer, dp[i]);
    }

    cout << answer;
    return 0;
}