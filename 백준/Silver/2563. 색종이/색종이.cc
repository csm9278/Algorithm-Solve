#include <iostream>
using namespace std;

int paper;
bool arr[101][101] = {false};

void Solve()
{
    cin >> paper;
    
    for(int i = 0; i < paper; i++)
    {
        int y, x;
        cin >> x >> y;

        for(int j = 0; j < 10; j++)
        for(int k = 0; k < 10; k++)
        {
            int gy = y + k;
            int gx = x + j;

            if(gy < 100 && gx < 100)
                arr[gy][gx] = true;
        }
    }

    int answer = 0;
    for(int i = 0; i < 100; i++)
    for(int j = 0; j < 100; j++)
    {
        if(arr[i][j])
            answer++;
    }

    cout << answer;
}

int main()
{
    Solve();
    return 0;
}