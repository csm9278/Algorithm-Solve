#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[301]; // dp 배열, 각 계단까지의 최대 점수를 저장
int scores[301]; // 각 계단의 점수 저장

int main() {
    int n; // 계단의 개수
    cin >> n;
    
    // 각 계단의 점수를 입력받음
    for(int i = 1; i <= n; i++) {
        int score;
        cin >> score;
        scores[i] = score;
    }

    // 계단의 개수에 따른 초기값 설정
    dp[1] = scores[1]; // 첫 번째 계단의 점수
    
    if (n >= 2) {
        dp[2] = scores[2] + dp[1]; // 첫 번째 계단과 두 번째 계단의 점수 합
    }

    if (n >= 3) {
        dp[3] = max(scores[3] + scores[1], scores[3] + scores[2]); // 두 가지 경우 비교
    }

    // 각 계단까지의 최대 점수를 계산
    for(int i = 4; i <= n; i++) {
        // i-3번째 계단과 i-1번째 계단을 밟은 경우 vs i-2번째 계단을 밟은 경우
        dp[i] = max(dp[i-3] + scores[i - 1] + scores[i], dp[i - 2] + scores[i]);
    }

    // 최종 결과 출력 (마지막 계단에서의 최대 점수)
    cout << dp[n];

    return 0;
}
