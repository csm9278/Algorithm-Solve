#include <string>
#include <vector>
#include <iostream>

using namespace std;

string number[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    string answer = "";
    string num = "";
    
    for(int i = 0 ; i < s.size(); i++)
    {
        if('a' <= s[i] && s[i] <= 'z')
        {
            num += s[i];
            for(int j = 0; j < 10; j++)
                if(number[j] == num)
                {
                    answer += to_string(j);
                    num = "";                 
                }
        }
        else
            answer += s[i];
    }
    
    return stoi(answer);
}