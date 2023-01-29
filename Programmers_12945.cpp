#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int iBefore = 0;
    int iNext = 1;
    for(int i=2;i<=n;++i)
    {
        answer = (iBefore+iNext)%1234567;
        iBefore = iNext;
        iNext = answer;
    }
    return answer;
}
