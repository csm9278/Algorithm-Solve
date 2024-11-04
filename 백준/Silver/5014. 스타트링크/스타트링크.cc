#include <iostream>
#include <queue>
using namespace std;

int n;  // 총 층수 F
int now, target;  // 현재 층 S, 목표 층 G
int up, down;  // U, D
bool visited[1000001] = {false};  // 최대 1,000,000 층

void Input() {
    cin >> n;          // F
    cin >> now >> target;  // S, G
    cin >> up >> down;  // U, D
}

void Solve() {
    queue<pair<int, int>> ques;
    ques.push({now, 0});
    visited[now] = true;

    int answer = -1;

    while (!ques.empty()) {
        int f = ques.front().first;
        int count = ques.front().second;
        ques.pop();

        if (f == target) {  // 목표 층 도달
            answer = count;
            break;
        }

        int u = f + up;
        if (u <= n && !visited[u]) 
        {
            ques.push({u, count + 1});
            visited[u] = true;
        }

        int d = f - down;
        if (d >= 1 && !visited[d]) 
        {
            ques.push({d, count + 1});
            visited[d] = true;
        }
    }

    if (answer != -1)
        cout << answer;
    else
        cout << "use the stairs";
}

int main() {
    Input();
    Solve();
    return 0;
}
