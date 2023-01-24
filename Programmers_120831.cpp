#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    n /= 2;
    answer = n * (n+1);
    return answer;
}
