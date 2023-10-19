#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(char a, char b)
{
    return a > b;
}

long long solution(long long n) {
    string num = to_string(n);
    sort(num.begin(), num.end(), cmp);
    
    return stol(num);
}