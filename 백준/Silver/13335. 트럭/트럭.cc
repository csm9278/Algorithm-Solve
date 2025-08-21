#include <iostream>
#include <queue>
using namespace std;

int tNum, maxTruck, maxHeignt, t = 0;
queue<int> ques;

void Input()
{
    cin >> tNum >> maxTruck >> maxHeignt;

    for(int i = 0; i < tNum; i++)
    {
        int h;
        cin >> h;
        ques.push(h);
    }
}

void Solve()
{
    int curHeight = maxHeignt;
    queue<int> bridgeQue;
    while(!ques.empty() || curHeight < maxHeignt)
    {
        t++;    //시간 증가

        if(bridgeQue.size() >= maxTruck)    //트럭 도착
        {
            int h = bridgeQue.front();
            curHeight += h;
            bridgeQue.pop();
        }

        int nextTruck = 0;
        if(!ques.empty())
            nextTruck = ques.front();

        if(!ques.empty() && curHeight - nextTruck >= 0)  //트럭이 다리에 올라갈 수 있다면
        {
            bridgeQue.push(nextTruck);
            curHeight -= nextTruck;
            ques.pop();
        }
        else
        {
            bridgeQue.push(0);
        }

    }
    cout << t;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();
    Solve();
    return 0;
}