#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int arr[101][101];
bool visited[101][101];

int dy[4] = {-1, 0, 1, 0}; // 상, 우, 하, 좌
int dx[4] = {0, 1, 0, -1};

void input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string row; 
        cin >> row; // 한 줄의 입력을 문자열로 받음
        for (int j = 0; j < m; j++) {
            arr[i][j] = row[j] - '0'; // 각 문자를 정수로 변환하여 배열에 저장
        }
    }
}

void Solve() {
    memset(visited, false, sizeof(visited));
    
    queue<pair<int, int>> ques;
    ques.push({0, 0});
    visited[0][0] = true;
    arr[0][0] = 1;  // 출발점의 거리를 1로 설정

    while (!ques.empty()) {
        int y = ques.front().first;
        int x = ques.front().second;
        ques.pop();

        for (int i = 0; i < 4; i++) {
            int gy = y + dy[i];
            int gx = x + dx[i];

            // 유효한 범위 내에 있고, 방문하지 않았으며 이동할 수 있는 칸(1)일 때
            if (gy >= 0 && gy < n && gx >= 0 && gx < m) {
                if (arr[gy][gx] == 1 && !visited[gy][gx]) { // 방문하지 않은 칸일 때만
                    ques.push({gy, gx});
                    visited[gy][gx] = true;
                    arr[gy][gx] = arr[y][x] + 1; // 현재까지의 거리에서 +1
                }
            }
        }
    }
}

int main() {
    input();
    Solve();

    // 도착지에 저장된 최단 거리를 출력
    cout << arr[n-1][m-1] << endl;
    return 0;
}
