#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n, m, k;
bool bKayak[11];
bool sKayak[11];

void Input()
{
    cin >> n >> m >> k;
}

void Solve()
{
    for(int i = 0; i < m; i++)
    {
        int broken;
        cin >> broken;
        bKayak[broken] = true;
    }

    for(int i = 0; i < k; i++)
    {
        int spair;
        cin >> spair;
        sKayak[spair] = true;
    }

    // 1. 자기 여분 카약 사용
    for (int i = 1; i <= n; i++) {
        if (bKayak[i] && sKayak[i]) {
            bKayak[i] = false;
            sKayak[i] = false;
        }
    }


    // 2. 앞 팀 → 뒷 팀 순서로 대여
    for (int i = 1; i <= n; i++) {
        if (bKayak[i]) {
            if (i - 1 >= 1 && sKayak[i - 1]) { // 앞 팀 확인
                bKayak[i] = false;
                sKayak[i - 1] = false;
            }
            else if (i + 1 <= n && sKayak[i + 1]) { // 뒷 팀 확인
                bKayak[i] = false;
                sKayak[i + 1] = false;
            }
        }
    }
    int answer = 0;
    for(int i = 1; i <= n; i++)
        if(bKayak[i])
            answer++;

    cout << answer;
}

int main()
{
    Input();
    Solve();

    return 0;
}