#include <string>
#include <vector>

using namespace std;

int arrCount[10] = {0,};

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    for(int iScore : score)
    {
        ++arrCount[iScore];
    }
    for(int i=k;i>=1;--i)
    {
        int iBox = arrCount[i] / m;
        answer += iBox * i * m;
        arrCount[i-1] += arrCount[i] % m;
    }
    return answer;
}
