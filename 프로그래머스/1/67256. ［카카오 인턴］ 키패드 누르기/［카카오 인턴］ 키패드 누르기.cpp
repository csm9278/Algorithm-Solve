#include <string>
#include <vector>
#include <iostream>

using namespace std;

int CheckCost(int number, int target)
{
    int cost = 0;
    while(number != target)
    {
        cost ++;
        if(target > number)
            if(target >= number + 3)
                number += 3;
            else
                number++;
        else
            if(target <= number - 3)
                number -= 3;
            else
                number--;
    }
    return cost;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int rNum = 12, lNum = 10;
    
    for(int i = 0 ; i < numbers.size(); i++)
    {
        if(numbers[i] == 1 ||numbers[i] == 4 || numbers[i] == 7)
        {
            answer += "L";
            lNum = numbers[i];
        }
        else if(numbers[i] == 3 ||numbers[i] == 6 || numbers[i] == 9)
        {
            answer += "R";
            rNum = numbers[i];
        }
        else
        {
            int target = numbers[i];
            if(target == 0)
                target = 11;
            
            int rCost = CheckCost(rNum, target);
            int lCost = CheckCost(lNum, target);
            
            if(rCost == lCost)
            {
                if(hand[0] == 'r')
                {
                    answer+= "R" ;
                    rNum = target;
                }
                else
                {
                    answer += "L";
                    lNum = target;
                    
                }
            }
            else if(rCost > lCost)
            {
                answer += "L";
                lNum = target;
            }
            else
            {
                answer += "R";
                rNum = target;
            }
            
        }
    }
    
    return answer;
}