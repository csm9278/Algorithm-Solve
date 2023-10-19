#include <string>
#include <vector>

using namespace std;

    int maxM[] = {31,29,31,30,31,30,31,31,30,31,30,31};
 string week[] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};

string solution(int a, int b) {
    int day = b;
    for(int i = 0; i < a-1; i++)
        day += maxM[i];
    
    return week[day % 7];
}