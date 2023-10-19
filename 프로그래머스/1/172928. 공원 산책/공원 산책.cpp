#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool p[51][51];

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int xSize, ySize;
    ySize = park.size();
    xSize = park[0].size();
    
    int nowX, nowY;
    int goX, goY;
    
    for(int i = 0; i < park.size(); i++)
    {
        for(int j = 0; j < park[i].size(); j++)
        {
            if(park[i][j] == 'O')
                p[i][j] = true;
            else if(park[i][j] == 'X')
                p[i][j] = false;
            else
            {
                nowX = j;
                nowY = i;
                p[i][j] = true;
            }
        }
    }
    
    for(int i = 0; i < routes.size(); i++)
    {
        int num = (int)routes[i][2] - '0';
        if(routes[i][0] == 'E')
        {
            goX = 1;
            goY = 0;
        }
        else if(routes[i][0] == 'W')
        {
            goX = -1;
            goY = 0;
        }
        else if(routes[i][0] == 'S')
        {
            goX = 0;
            goY = 1;
        }
        else if(routes[i][0] == 'N')
        {
            goX = 0;
            goY = -1;
        }
        
        bool pass = false;
        for(int j = 1; j <= num; j++)
        {
            
            if(!p[nowY+ j * goY][nowX + j * goX])
            {
                pass = true;
                break;
            }
            else if(nowY+ j * goY > ySize || nowX + j * goX > xSize ||
                    nowX + j * goX < 0 || nowX + j * goX > ySize < 0)
            {
                pass = true;
                break;
            }
        }
        
        if(!pass)
        {
            nowX += num * goX;
            nowY += num * goY;
        }
        
    }
    
    answer.push_back(nowY);
    answer.push_back(nowX);
    
    return answer;
}