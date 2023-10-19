#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int nn;
bool cmp(string a, string b)
{
    if(a[nn] == b[nn])
        for(int i = 0; i < a.size(); i++)
            if(a[i] != b[i])
                return a[i] < b[i];
            
    return a[nn] < b[nn];
}

vector<string> solution(vector<string> strings, int n) {
    nn = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}