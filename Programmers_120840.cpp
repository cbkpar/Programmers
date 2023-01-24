#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    long long answer = 1;
    if(balls-share < share) share = balls-share;
    for(int i=1;i<=share;++i)
    {
        answer *= balls - i + 1;
        answer /= i;
    }
    return (int)answer;
}
