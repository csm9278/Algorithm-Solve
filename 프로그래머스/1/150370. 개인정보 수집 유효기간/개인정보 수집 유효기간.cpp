#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int changeDate(string date)
{
    int num = 0;
    
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8,2));
    
    cout << year << " : " << month << " : " << day << endl;
    
    year *=  336;
    month *= 28;
    
    
    num = year + month + day;
    return num;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> maps;
    
    int now = changeDate(today);
    
    for(int i = 0 ; i< terms.size(); i++)
    {
        char kind = terms[i][0];
        int num = stoi(terms[i].substr(2));

        maps[kind] = num;
    }
    
    for(int i = 0 ; i < privacies.size(); i++)
    {
        int p = changeDate(privacies[i].substr(0, 10));
        char kind = privacies[i][privacies[i].size() - 1];
        cout << now - p << endl;
        
        if(maps.find(kind) != maps.end())
        {
            int diff = maps[kind] * 28;
            cout << diff << endl;
            if(now - p >= diff)
            {
                answer.push_back(i + 1);
            }
        }
        
    }
    
    
    return answer;
}