#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int n;
int maxNum = INT_MIN, minNum = INT_MAX;
vector<int> nums;

int add, sub, mul, divi;

void DFS(int idx, int add, int sub, int mul, int divi, int result)
{
    if(idx == n)
    {
        maxNum = max(maxNum, result);
        minNum = min(minNum, result);
        return;
    }

    if(add > 0)
        DFS(idx + 1, add - 1, sub, mul, divi, result + nums[idx]);
    
    if(sub > 0)
        DFS(idx + 1, add, sub - 1, mul, divi, result - nums[idx]);

    if(mul > 0)
        DFS(idx + 1, add, sub, mul - 1, divi, result * nums[idx]);

    if(divi > 0)
        DFS(idx + 1, add, sub, mul, divi - 1, result / nums[idx]);
}

int main()
{

    int answer;
    cin >> n;

    nums.resize(n);
    vector<int> operVec(4);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cin >> add >> sub >> mul >> divi;


    DFS(1, add, sub, mul, divi, nums[0]);
    cout << maxNum << endl << minNum;

    return 0;

}