#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    //1. 대문자 소문자 변경
    for(int i = 0 ; i < new_id.size(); i++)
        if('A' <= new_id[i] && new_id[i] <= 'Z')
            new_id[i] -= 'A' - 'a';
    
    //2. 문자 예외처리
    for(int i = 0 ; i < new_id.size(); i++)
        if(!('a' <= new_id[i] && new_id[i] <= 'z') &&
          new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.')
            if(isdigit(new_id[i]) == 0)
            {
                new_id.erase(new_id.begin() + i);
                i--;
            }
    
    //3~4 .개수 하나로 치환과 맨 앞 뒤면 제거
    for(int i = 0 ; i < new_id.size() - 1; i++)
        if(new_id[i] == '.')
            if(new_id[i + 1] == '.')    
            {
                new_id.erase(new_id.begin() + i);
                i--;
            }
    
    if(new_id[0] == '.')
        new_id.erase(new_id.begin());
    
    if(new_id[new_id.size() - 1] == '.')
        new_id.erase(new_id.end() - 1);
    
    //5. 빈문자열 a 삽입
    if(new_id == "")
        new_id = "a";
    
    //6. 사이즈 조절
    if(new_id.size() >= 16)
    {
        new_id.erase(new_id.begin() + 15, new_id.end());
        
        if(new_id[new_id.size() - 1] == '.')
            new_id.erase(new_id.end() - 1);
    }

    //7. 2자이하 조절
    if(new_id.size() <= 2)
        while(new_id.size() < 3)
            new_id += new_id[new_id.size() - 1];
    
    
    return new_id;
}