#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int target;
int kind;
stack<int> st;
int ans;

void Input()
{
    cin >> kind >> target;

    for(int i = 0; i < kind; i++)
    {
        int coin;
        cin >> coin;
        st.push(coin);
    }
}

void Solve()
{
    int curTarget = 0;

    while(curTarget < target)
    {
        int coin = st.top();
        if(curTarget + coin <= target)
        {
            curTarget += coin;
            ans++;
        }
        else
            st.pop();
    }
}

int main()
{
    Input();
    Solve();
    cout << ans;
}
