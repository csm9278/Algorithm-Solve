#include <iostream>
#include <vector>
using namespace std;

int dp[1001][31][3];  // dp[time][move][tree] : tree는 1번 나무와 2번 나무 (1 또는 2)

int main() {
    int T, W;  // T: 자두가 떨어지는 총 시간, W: 최대 이동 횟수
    cin >> T >> W;

    vector<int> plums(T + 1);  // 각 시간에 자두가 떨어지는 나무 (1번 나무에서 떨어지면 1, 2번 나무에서 떨어지면 2)
    for (int i = 1; i <= T; i++) {
        cin >> plums[i];
    }

    // DP 테이블 초기화
    if (plums[1] == 1) dp[1][0][1] = 1;  // 첫 번째 자두가 1번 나무에서 떨어지면
    else dp[1][0][1] = 0;

    if (plums[1] == 2) dp[1][1][2] = 1;  // 첫 번째 자두가 2번 나무에서 떨어지면
    else dp[1][1][2] = 0;

    // DP 계산
    for (int time = 2; time <= T; time++) {
        for (int move = 0; move <= W; move++) {
            // 1번 나무에 있는 경우
            dp[time][move][1] = dp[time-1][move][1] + (plums[time] == 1 ? 1 : 0);  // 1번 나무에서 자두를 잡는 경우
            if (move > 0) {
                dp[time][move][1] = max(dp[time][move][1], dp[time-1][move-1][2] + (plums[time] == 1 ? 1 : 0));  // 2번 나무에서 이동한 경우
            }

            // 2번 나무에 있는 경우
            dp[time][move][2] = dp[time-1][move][2] + (plums[time] == 2 ? 1 : 0);  // 2번 나무에서 자두를 잡는 경우
            if (move > 0) {
                dp[time][move][2] = max(dp[time][move][2], dp[time-1][move-1][1] + (plums[time] == 2 ? 1 : 0));  // 1번 나무에서 이동한 경우
            }
        }
    }

    // 최대값 계산
    int answer = 0;
    for (int move = 0; move <= W; move++) {
        answer = max(answer, max(dp[T][move][1], dp[T][move][2]));  // 최종적으로 최대 자두 개수를 계산
    }

    cout << answer << endl;  // 최대 자두 개수 출력
    return 0;
}
