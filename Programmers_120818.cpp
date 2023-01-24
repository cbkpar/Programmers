#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    int answer = price;
    if(price < 100000)
    {
        answer *= 100;
    }
    else if(price < 300000)
    {
        answer *= 95;
    }
    else if(price < 500000)
    {
        answer *= 90;
    }
    else
    {
        answer *= 80;
    }
    answer /= 100;
    return answer;
}
