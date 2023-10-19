#include <string>
#include <vector>
#include <iostream>

using namespace std;

int numbers[1001][1001] = {0};

vector<int> solution(int n) 
{
    vector<int> answer;
    
    int count = 1;
    int curN = n;
    int x = 0;
    int y = 0;
    int roopTime = 0;
    
    
    int state = 0;  //0 down / 1 right / 2 up

    if(n == 1)
    {
        answer.push_back(1);
        return answer;
    }
        
    
    while(curN > 1)
    {
        
        switch(state)
        {
            case 0: // 아래쪽 내려가기
                if(numbers[y][x] == 0)
                {
                    numbers[y][x] = count;
                    count++;
                }

                if(y + 1 < curN)
                {
                    y++;
                }
                else
                {
                    state = 1;
                }
                break;
            case 1: // 오른쪽 전진
                if(numbers[y][x] == 0)
                {
                    numbers[y][x] = count;
                    count++;
                }
                if(x + 1 < curN - roopTime)
                {
                    x++;
                }
                else
                {
                    state = 2;
     
                }
                break;
            case 2:// 위쪽 올라가기
                if(numbers[y][x] == 0)
                {
                    numbers[y][x] = count;
                    count++;
                }
                if(numbers[y - 1][x - 1] == 0)
                {
                    y--;
                    x--;
                }
                else
                {
                    state = 0;
                    curN--;
                    roopTime++;
                }
                break;
        }
    }
    
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < i + 1; j++)
            answer.push_back(numbers[i][j]);
    }
    
    return answer;
}