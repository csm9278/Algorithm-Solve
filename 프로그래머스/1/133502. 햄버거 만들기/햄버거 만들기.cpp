#include <string>
#include <vector>
#include <iostream>

using namespace std;


int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> vecs;
    vecs.push_back(ingredient[0]);
    
    for(int i = 1 ; i < ingredient.size(); i++)
    {
        if(vecs.back() == 1 && ingredient[i] == 2) vecs.back() = 12;
        else if(vecs.back() == 12 && ingredient[i] == 3) vecs.back() = 123;
        else if(vecs.back() == 123 && ingredient[i] == 1) {vecs.pop_back(); answer++;}
        else
            vecs.push_back(ingredient[i]);
    }
    
    
    return answer;
}