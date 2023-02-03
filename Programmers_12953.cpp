#include <string>
#include <vector>

using namespace std;

int gcd(int iA, int iB)
{
    if(iB%iA==0) return iA;
    return gcd(iB%iA,iA);
}

int solution(vector<int> arr) {
    int answer = 1;
    for(int iNum : arr)
    {
        int iGCD = (iNum<answer?gcd(iNum,answer):gcd(answer,iNum));
        answer /= iGCD;
        answer *= iNum;
    }
    return answer;
}
