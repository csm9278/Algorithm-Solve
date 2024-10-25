#include <iostream>
#include <algorithm>

using namespace std;

int dp[10001];
int lums[10001];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> lums[i];
    }

    dp[1] = lums[1];
    if (n > 1) {
        dp[2] = lums[1] + lums[2];
    }
    if (n > 2) {
        dp[3] = max({lums[3] + lums[2], lums[3] + lums[1], dp[2]});
    }

    for (int i = 4; i <= n; i++) {
        dp[i] = max({dp[i - 1], dp[i - 2] + lums[i], dp[i - 3] + lums[i - 1] + lums[i]});
    }

    cout << dp[n] << endl;
    return 0;
}
