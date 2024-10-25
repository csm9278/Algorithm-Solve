#include <iostream>
#include <algorithm>
using namespace std;

int N;
int T[1500001], P[1500001], dp[1500001]; // T는 상담 기간, P는 상담 금액, dp는 최대 수익

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> T[i] >> P[i];
    }

    // DP를 이용하여 최대 수익 계산
    for (int i = 1; i <= N; ++i) {
        if (i + T[i] - 1 <= N) {
            dp[i + T[i] - 1] = max(dp[i + T[i] - 1], dp[i - 1] + P[i]);
        }
        dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << dp[N] << endl;
    return 0;
}
