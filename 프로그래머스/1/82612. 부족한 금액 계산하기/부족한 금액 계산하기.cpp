using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long money2 = money;
    long long need = 0;
    for(int i = 0 ; i < count; i++)
        need += price + (price * i);
    
    money2 -= need;
    if(money2 < 0)
        answer = -money2;
    else
        answer = 0;

    return answer;
}