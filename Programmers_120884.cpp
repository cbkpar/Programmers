#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    while(chicken >= 10)
    {
        int iPlus = chicken / 10;
        answer += iPlus;
        chicken -= iPlus * 9;
    }
    return answer;
}
