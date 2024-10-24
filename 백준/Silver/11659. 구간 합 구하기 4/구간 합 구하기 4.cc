#include <iostream>
using namespace std;

int dp[100001];


int main()
{

    ios::sync_with_stdio(false); // C의 표준 입출력과 동기화 해제
    cin.tie(NULL); // cin과 cout의 묶음을 풀어서 성능 향상

    int n, m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        dp[i] = dp[i - 1] + num;
    }

    for(int i =0; i < m; i++)
    {
        int j, k;
        cin >> j >> k;

        cout << dp[k] - dp[j - 1] << '\n';
    }

    return 0;
}