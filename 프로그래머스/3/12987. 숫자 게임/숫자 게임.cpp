#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int aIdx = 0, bIdx = 0;
    while(aIdx < A.size() && bIdx < B.size())
    {
        if(A[aIdx] >= B[bIdx])
            bIdx++;
        else
        {
            answer++;
            aIdx++;
            bIdx++;
        }
    }
    return answer;
}