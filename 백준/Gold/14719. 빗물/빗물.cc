#include <iostream>
using namespace std;

int x, y;
bool arr[501][501] = {false};
int answer = 0;

void Input()
{
    cin >> y >> x;

    for(int i = 0; i < x; i++)
    {
        int wall;
        cin >> wall;
        for(int j = 0; j < wall; j++)
        {
            arr[j][i] = true;
        }
    }
}

void Solve()
{
    for(int i = 0; i < y; i++)
    {
        int area = 0;
        bool blocked = false;

        for(int j = 0; j < x; j++)
        {
            if(arr[i][j])
            {
                if(!blocked)
                    blocked = true;
                else
                {
                    answer += area;
                    area = 0;
                }
            }
            else
            {
                if(blocked)
                    area++;
            }

        }
    }
    cout << answer;
}



int main()
{   
    Input();
    Solve();
    return 0;
}