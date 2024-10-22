#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int arr[1001][1001];  // 토마토 저장
bool visited[1001][1001];  // 방문 여부 체크
int day = 0;  // 날짜 카운트

int dy[4] = {-1, 0, 1, 0};  // 상, 우, 하, 좌
int dx[4] = {0, 1, 0, -1};

void input() {
    cin >> m >> n;  // m: 가로, n: 세로

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];  // 토마토 상태 입력
}

void Solve() {
    memset(visited, false, sizeof(visited));
    
    queue<pair<int, int>> ques;
    bool allRipe = true;  // 처음부터 모든 토마토가 익어있는지 여부
    
    // 초기 익은 토마토들을 큐에 넣음
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {  // 익은 토마토
                ques.push({i, j});
                visited[i][j] = true;
            }
            if (arr[i][j] == 0) {  // 익지 않은 토마토가 있다면
                allRipe = false;
            }
        }
    }

    // 이미 모든 토마토가 익어있다면
    if (allRipe) {
        cout << 0 << endl;
        return;
    }

    // BFS 탐색 시작
    while (!ques.empty()) {
        int count = ques.size();  // 현재 큐에 있는 익은 토마토의 개수
        
        for (int i = 0; i < count; i++) {
            int y = ques.front().first;
            int x = ques.front().second;
            ques.pop();
            
            for (int j = 0; j < 4; j++) {
                int gy = y + dy[j];
                int gx = x + dx[j];
                
                if (gy >= 0 && gy < n && gx >= 0 && gx < m) {  // 유효한 범위 내
                    if (!visited[gy][gx] && arr[gy][gx] == 0) {  // 익지 않은 토마토라면
                        arr[gy][gx] = 1;  // 토마토를 익힘
                        ques.push({gy, gx});  // 큐에 추가
                        visited[gy][gx] = true;  // 방문 체크
                    }
                }
            }
        }
        
        if (!ques.empty()) {
            day++;  // 하루 경과
        }
    }

    // 모든 토마토가 익었는지 확인
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {  // 익지 않은 토마토가 남아있다면
                cout << -1 << endl;
                return;
            }
        }
    }

    // 모든 토마토가 익었으면 날짜 출력
    cout << day << endl;
}

int main() {
    input();
    Solve();
    return 0;
}
