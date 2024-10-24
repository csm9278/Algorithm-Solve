#include <iostream>
using namespace std;

int dp[1001];  // dp 배열, 돌의 개수에 따라 상근이가 이길지 창영이가 이길지 저장

int main() {
    int N;
    cin >> N;

    dp[1] = 1;  // 상근이가 이김
    dp[2] = 0;  // 창영이가 이김
    dp[3] = 1;  // 상근이가 이김

    // N이 4 이상일 때 점화식에 따라 계산
    for (int i = 4; i <= N; i++) {
        if (dp[i-1] == 0 || dp[i-3] == 0) {
            dp[i] = 1;  // 상근이가 이길 수 있는 상황
        } else {
            dp[i] = 0;  // 창영이가 이길 수 있는 상황
        }
    }

    // 결과 출력
    if (dp[N] == 1) {
        cout << "SK" << endl;  // 상근이가 이기면 SK 출력
    } else {
        cout << "CY" << endl;  // 창영이가 이기면 CY 출력
    }

    return 0;
}
