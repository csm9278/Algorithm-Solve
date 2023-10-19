#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> maps;
    
    maps['R'] =0;
    maps['T'] =0;
    maps['C'] =0;
    maps['F'] =0;
    maps['J'] =0;
    maps['M'] =0;
    maps['A'] =0;
    maps['N'] =0;
    
    for(int i = 0; i < survey.size(); i++)
    {   
        if(choices[i] < 4)
            maps[survey[i][0]] += 4 - choices[i];        
        else if(4 < choices[i])
            maps[survey[i][1]] += choices[i] - 4;     
    }
    
    if(maps['R'] >= maps['T'])
        answer += "R";
    else
        answer += "T";
    
    if(maps['C'] >= maps['F'])
        answer += "C";
    else
        answer += "F";
    
    if(maps['J'] >= maps['M'])
        answer += "J";
    else
        answer += "M";
    
    if(maps['A'] >= maps['N'])
        answer += "A";
    else
        answer += "N";
    
    return answer;
}