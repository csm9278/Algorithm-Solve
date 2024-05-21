#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
map<string, int> no = {{"code", 0}, {"date", 1}, {"maximum", 2}, {"remain", 3}};

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) 
{
    vector<vector<int>> answer;
    
    int extIdx = no[ext];

    for(int i = 0; i < data.size(); i++)
    {
        if(data[i][extIdx] < val_ext)
            answer.push_back(data[i]);
    }


    sort(answer.begin(), answer.end(), [&sort_by](vector<int> a, vector<int> b){
        return a[no[sort_by]] < b[no[sort_by]];
    });
    return answer;
}