#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool upsort(int& a, int& b)
{
    return a > b;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), upsort);
    
    for(int i = 0; i < A.size(); i++)
    {
        answer += A[i] * B[i];
    }
        
    return answer;
}