#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int first = number[0] - '0';
    int idx = 0;
    for(int i = 0 ; i < number.size() - k; i++)
    {
        char maxint = number[idx];
        int maxidx = idx;
        for(int j = idx; j <= k+i; j++){
            if(maxint < number[j]){ 
                maxint = number[j];
                maxidx = j;
            }
        }
        idx = maxidx + 1; 
        answer += maxint;
        
    }
    
    cout << first << " : " << idx << endl;
   
    return answer;
}