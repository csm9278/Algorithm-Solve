#include <iostream>
#include <queue>
using namespace std;

int caseNum;
vector<int> nums;
vector<pair<int,int>> startVec;
vector<pair<int,int>> targetVec;

int dy[] = {2,1,-1,-2,-2,-1,1,2};
int dx[] = {1,2,2,1,-1,-2,-2,-1};

void Input()
{   
    cin >> caseNum;
    for(int i = 0 ; i < caseNum; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
        int start, start2;
        int target, target2;

        cin >> start >> start2;
        cin >> target >> target2;

        startVec.push_back({start, start2});
        targetVec.push_back({target, target2});
    }
}

void BFS(int idx)
{
    int grid = nums[idx];
    pair<int, int> start = startVec[idx];
    pair<int, int> target = targetVec[idx];

    if (start == target)
    {
       cout << 0 << endl;
       return;
    }  

    queue<pair<int, int>> ques;
    ques.push(start);
    bool visited[301][301] = {false};  // 매번 초기화
    visited[start.first][start.second] = true;
    int count = 0;
    while(!ques.empty())
    {
        int queSize = ques.size();
        for(int s = 0; s < queSize; s++)
        {
            int y = ques.front().first;
            int x = ques.front().second;
            ques.pop();

            for(int i = 0; i < 8; i++)
            {
                int gy = y + dy[i];
                int gx = x + dx[i];
                if (gy == target.first && gx == target.second) {
                    cout << count + 1 << endl;
                    return;
                }

                if(gy < grid && gy >= 0 && gx < grid && gx >= 0)
                if(!visited[gy][gx])
                {
                    ques.push({gy, gx});
                    visited[gy][gx] = true;
                }
            }
        }
        count++;
        
    }
    cout << count << endl;
}

void Solve()
{
    for(int i = 0; i < caseNum; i++)
    {
        BFS(i);
    }
}



int main()
{
    Input();
    Solve();

    return 0;
}