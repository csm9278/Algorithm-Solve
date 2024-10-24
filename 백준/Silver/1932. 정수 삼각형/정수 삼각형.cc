#include <iostream>
#include <vector>
using namespace std;

int dp[501][501]; // DP 배열, 각 위치까지의 최대 경로 합을 저장
int answer = 0;   // 최종 답을 저장할 변수

int main()
{
    int n; 
    cin >> n; // 삼각형의 크기 입력

    // 2차원 벡터로 삼각형의 숫자들을 저장할 공간 할당
    vector<vector<int>> vecs;
    vecs.resize(n + 1); // n+1 크기로 벡터 크기 조정 (1번부터 사용하기 위해서)

    // 삼각형 데이터 입력
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int num;
            cin >> num; // 각 숫자 입력
            vecs[i].push_back(num); // i번째 줄에 숫자 저장
        }
    }

    // 첫 번째 값 초기화
    dp[1][0] = vecs[1][0]; // 맨 꼭대기의 값은 자기 자신이 최댓값

    // DP 진행: 2번째 줄부터 마지막 줄까지 최댓값을 계산
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < vecs[i].size(); j++) {
            if (j == 0) 
                // 가장 왼쪽 요소: 바로 위의 값에서만 내려올 수 있음
                dp[i][j] = dp[i - 1][j] + vecs[i][j];
            else if (j == vecs[i].size() - 1) 
                // 가장 오른쪽 요소: 바로 위의 대각선 왼쪽에서만 내려올 수 있음
                dp[i][j] = dp[i - 1][j - 1] + vecs[i][j];
            else 
                // 중간 요소: 대각선 왼쪽 또는 대각선 오른쪽 중 더 큰 값에서 내려옴
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + vecs[i][j];
        }
    }

    // 마지막 줄에서 최댓값 찾기
    for (int i = 0; i < vecs[n].size(); i++)
        answer = max(dp[n][i], answer); // 마지막 줄에서 최대값 갱신

    // 최종 결과 출력
    cout << answer;
    return 0;
}
