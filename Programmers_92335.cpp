#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool bIsPrime(long long lN)
{
    if(lN<=1) return false;
    long long lSqrt = sqrt(lN);
    for(long long i=2;i<=lSqrt;++i)
    {
        if(lN%i==0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    long long lNumber = 0;
    while(n)
    {
        lNumber *= 10;
        lNumber += n%k;
        n/=k;
    }
    long long lTemp = 0;
    while(lNumber)
    {
        lTemp *= 10;
        lTemp += lNumber%10;
        lNumber /= 10;
        if(lNumber%10 == 0)
        {
            if(bIsPrime(lTemp)) ++answer;
            lTemp = 0;
            lNumber /= 10;
        }
    }
    return answer;
}
