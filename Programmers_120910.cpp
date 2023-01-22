#include <string>
#include <vector>

using namespace std;

int solution(int n, int t) {
    int answer = n;
    while(t--)
    {
        answer *= 2;
    }
    return answer;
}
