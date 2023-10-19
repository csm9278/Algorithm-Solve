#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> answer;
    int aCount[] = {1, 2, 3, 4, 5 };
    int bCount[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int cCount[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int aSize = sizeof aCount / sizeof aCount[0];
    int bSize = sizeof bCount / sizeof bCount[0];
    int cSize = sizeof cCount / sizeof cCount[0];
    int aNum = 0, bNum = 0, cNum = 0;
    int maxNum = 0;
    
    
    for(int i = 0; i < answers.size(); i++)
    {
        if(answers[i] == aCount[i % aSize])
            aNum++;
        
        if(answers[i] == bCount[i % bSize])
            bNum++;
        
        if(answers[i] == cCount[i % cSize])
            cNum++;
    }
    
    maxNum = max(aNum, max(bNum, cNum));
    
    cout << "A : " << aNum << " " << "B : " << bNum << " " << "C : " << cNum;
    if(aNum == maxNum)
        answer.push_back(1);
    if(bNum == maxNum)
        answer.push_back(2);
    if(cNum == maxNum)
        answer.push_back(3);
    
    
    return answer;
}