#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    if(arr.size() == 1)
    {
        arr.clear();
        arr.push_back(-1);
        return arr;        
    }
    
    int idx = 0;
    int num = arr[0];
    for(int i = 1; i < arr.size(); i++)
        if(num > arr[i])
        {
            num = arr[i];
            idx = i;
        }
    
    arr.erase(arr.begin() + idx);
    
    return arr;
}