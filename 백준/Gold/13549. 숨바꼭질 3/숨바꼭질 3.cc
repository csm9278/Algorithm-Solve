#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n, target;
int visited[100001];  // 방문 여부 및 도달 시간을 기록하는 배열

void Input() {
    fill(visited, visited + 100001, 100001);  // 초기화
    cin >> n >> target;
}

void Solve() {
    if (n == target) {  // 시작 위치와 목표 위치가 같다면
        cout << 0 << endl;
        return;
    }

    deque<pair<int, int>> dq;
    dq.push_front({n, 0});  // 시작 위치와 초기 시간
    visited[n] = 0;

    while (!dq.empty()) {
        int now = dq.front().first;
        int count = dq.front().second;
        dq.pop_front();

        // 목표 위치에 도달하면 바로 결과 출력 후 종료
        if (now == target) {
            cout << count << endl;
            return;
        }

        // 순간이동 (우선 탐색)
        if (now * 2 <= 100000 && visited[now * 2] > count) {
            dq.push_front({now * 2, count});  // 순간 이동은 비용 0
            visited[now * 2] = count;
        }

        // 걸어서 이동하는 경우들
        if (now + 1 <= 100000 && visited[now + 1] > count + 1) {
            dq.push_back({now + 1, count + 1});
            visited[now + 1] = count + 1;
        }

        if (now - 1 >= 0 && visited[now - 1] > count + 1) {
            dq.push_back({now - 1, count + 1});
            visited[now - 1] = count + 1;
        }
    }
}

int main() {
    Input();
    Solve();
    return 0;
}
