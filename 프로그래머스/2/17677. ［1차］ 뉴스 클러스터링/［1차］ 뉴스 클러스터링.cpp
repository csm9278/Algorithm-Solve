#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctype.h>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int min = 0, max = 0;
    vector<string> vecs, vecs2;
    
    for(int i = 0; i < str1.size(); i++)
        str1[i] = tolower(str1[i]);
    for(int i = 0; i < str2.size(); i++)
        str2[i] = tolower(str2[i]);

    float jak = 0.0f;
    for(int i = 0 ; i < str1.size() - 1; i++)
    {
        string str = str1.substr(i, 2);
        if(!isalpha(str[0]) || !isalpha(str[1]))
            continue;
        vecs.push_back(str);
    } 
    
    for(int i = 0 ; i < str2.size() - 1; i++)
    {
        string str = str2.substr(i, 2);
        if(!isalpha(str[0]) || !isalpha(str[1]))
            continue;
        vecs2.push_back(str);
    } 

    if(vecs.empty() && vecs2.empty())
        return 65536;
    
    max = vecs.size() + vecs2.size();
    
    if(vecs.size() > vecs2.size()){
        for(int i = 0; i < vecs2.size(); i++)
        {
            auto itr = find(vecs.begin(), vecs.end(), vecs2[i]);
            if(itr != vecs.end())
            {
                min++;
                vecs.erase(itr);
            }
        }
    }
    else
        for(int i = 0; i < vecs.size(); i++)
        {
            auto itr = find(vecs2.begin(), vecs2.end(), vecs[i]);
            if(itr != vecs2.end())
            {
                min++;
                vecs2.erase(itr);
            }
        }
    
    max -= min;
    
    if(max == 0)
        return 65536;
        
    double tmp = (double)min / (double)max;
    
    return tmp * 65536;
}