#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
bool bKayak[11]; // 부서진 카약 여부
bool spare[11];  // 여분 카약 여부

void Input() {
    cin >> n >> m >> k;
}

void Solve() {
    // 부서진 카약 정보 입력
    for (int i = 0; i < m; i++) {
        int broken;
        cin >> broken;
        bKayak[broken] = true;
    }

    // 여분 카약 정보 입력
    for (int i = 0; i < k; i++) {
        int spair;
        cin >> spair;
        spare[spair] = true;
    }

    // 1. 자기 여분 카약 사용
    for (int i = 1; i <= n; i++) {
        if (bKayak[i] && spare[i]) {
            bKayak[i] = false;
            spare[i] = false;
        }
    }

    // 2. 앞 팀 → 뒷 팀 순서로 대여
    for (int i = 1; i <= n; i++) {
        if (bKayak[i]) {
            if (i - 1 >= 1 && spare[i - 1]) { // 앞 팀 확인
                bKayak[i] = false;
                spare[i - 1] = false;
            }
            else if (i + 1 <= n && spare[i + 1]) { // 뒷 팀 확인
                bKayak[i] = false;
                spare[i + 1] = false;
            }
        }
    }

    // 3. 출발 못하는 팀 계산
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (bKayak[i]) {
            answer++;
        }
    }

    cout << answer << "\n";
}

int main() {
    Input();
    Solve();
    return 0;
}
