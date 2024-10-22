#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool visited[100001]; // 방문 체크 배열

void Input() {
    cin >> n >> m;
}

void Solve() {
    queue<pair<int, int>> ques; // 현재 위치와 시간을 함께 저장
    ques.push({n, 0});
    visited[n] = true;

    while(!ques.empty()) {
        int cur = ques.front().first;
        int time = ques.front().second;
        ques.pop();

        if (cur == m) {
            cout << time << endl;
            return;
        }

        // 걷기: cur - 1, cur + 1, 순간이동: cur * 2
        if (cur - 1 >= 0 && !visited[cur - 1]) {
            ques.push({cur - 1, time + 1});
            visited[cur - 1] = true;
        }
        if (cur + 1 <= 100000 && !visited[cur + 1]) {
            ques.push({cur + 1, time + 1});
            visited[cur + 1] = true;
        }
        if (cur * 2 <= 100000 && !visited[cur * 2]) {
            ques.push({cur * 2, time + 1});
            visited[cur * 2] = true;
        }
    }
}

int main() {
    Input();
    Solve();
    return 0;
}