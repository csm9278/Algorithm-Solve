#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> vecs(n);
    for (int i = 0; i < n; i++) {
        cin >> vecs[i];
    }
    
    // 내림차순 정렬
    sort(vecs.begin(), vecs.end(), greater<int>());
    
    int answer = 0;
    for (int i = 0; i < n; i++) {
        // 현재까지의 최대 중량 갱신
        answer = max(answer, vecs[i] * (i + 1));
    }
    
    cout << answer << endl;
    return 0;
}
