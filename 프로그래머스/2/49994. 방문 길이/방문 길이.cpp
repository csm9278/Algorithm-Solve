#include <string>
#include <map>
using namespace std;

class Point
{
    public:
    int xx;
    int yy;
    
    Point()
    {
        xx = 0;
        yy = 0;
    }
    
    Point(int x, int y)
    {
        xx = x;
        yy = y;
    }
};

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};

char dir[] = {'U', 'D', 'R', 'L'};

int solution(string dirs) {
    int answer = 0;
    
    map<pair<pair<int,int>,pair<int,int>>, int> maps;
    Point nowPoint;
    
    for(int i = 0 ; i < dirs.size(); i++){
        Point goPoint(0, 0);
        int d = 0;
        for(int j = 0; j < 4; j++){
            if(dirs[i] == dir[j]){
                d = j;
                break;
            }
        }
        
        goPoint.xx = nowPoint.xx + dx[d];
        goPoint.yy = nowPoint.yy + dy[d];
        if(5 < goPoint.yy || goPoint.yy < -5 || 5 < goPoint.xx || goPoint.xx < -5)
            continue;
        
        if(maps.find({{nowPoint.yy, nowPoint.xx}, {goPoint.yy, goPoint.xx}})
           == maps.end()){
            maps[{{nowPoint.yy, nowPoint.xx}, {goPoint.yy, goPoint.xx}}] = 1;
            maps[{{goPoint.yy, goPoint.xx}, {nowPoint.yy, nowPoint.xx}}] = 1;
            answer++;
        }
        nowPoint = goPoint;
        
    }
    
    
    return answer;
}