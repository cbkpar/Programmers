#include <string>
#include <vector>

using namespace std;

bool IsPrime(int iNum)
{
    for(int i=2;i<iNum;++i)
    {
        if(iNum%i==0)
        {
            return false;
        }
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    for(int i=3;i<=n;++i)
    {
        if(!IsPrime(i))
        {
            ++answer;
        }
    }
    return answer;
}
