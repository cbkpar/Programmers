#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n>=a)
    {
        int iCount = n/a;
        n -= iCount * a;
        answer += iCount * b;
        n += iCount * b;
    }
    return answer;
}
