#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v; // 정점의 개수, 간선의 개수, 시작 정점
vector<vector<int>> vecs; // 인접 리스트
vector<bool> visited; // 방문 여부 배열

// 입력 함수
void Input() {
    cin >> n >> m >> v; // 정점의 개수, 간선의 개수, 시작 정점 입력
    vecs.resize(n + 1); // 정점 번호는 1부터 시작하므로 크기 n+1
    visited.resize(n + 1, false); // 방문 여부 배열 초기화
    
    // 간선 입력
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vecs[a].push_back(b); // 정점 a와 b를 연결
        vecs[b].push_back(a); // 양방향 간선
    }
    
    // 인접 리스트 정렬 (작은 정점 번호부터 방문하기 위함)
    for (int i = 1; i <= n; i++)
        sort(vecs[i].begin(), vecs[i].end());
}

// DFS 함수
void DFS(int v) {
    visited[v] = true; // 현재 정점 방문 처리
    cout << v << " "; // 현재 정점 출력
    
    // 인접한 정점들 방문
    for (int i = 0; i < vecs[v].size(); i++) {
        if (!visited[vecs[v][i]]) {
            DFS(vecs[v][i]); // 재귀 호출로 깊이 우선 탐색
        }
    }
}

// BFS 함수
void BFS(int v) {
    queue<int> ques; // BFS를 위한 큐
    visited[v] = true; // 현재 정점 방문 처리
    ques.push(v); // 큐에 현재 정점 추가
    
    while (!ques.empty()) {
        int num = ques.front();
        ques.pop();
        cout << num << " "; // 현재 정점 출력
        
        // 인접한 정점들 방문
        for (int i = 0; i < vecs[num].size(); i++) {
            if (!visited[vecs[num][i]]) {
                ques.push(vecs[num][i]); // 큐에 인접 정점 추가
                visited[vecs[num][i]] = true; // 방문 처리
            }
        }
    }
    cout << endl;
}

int main() {
    Input(); // 입력 받기
    DFS(v); // DFS 수행
    cout << endl;
    fill(visited.begin(), visited.end(), false); // 방문 여부 초기화
    BFS(v); // BFS 수행
    return 0;
}
