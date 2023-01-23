#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if(a%b==0) return b;
    return gcd(b, a%b);
}

int solution(int a, int b) {
    int iGCD = (a>b?gcd(a,b):gcd(b,a));
    b /= iGCD;
    while(true)
    {
        if(b%2 != 0) break;
        b /= 2;
    }
    while(true)
    {
        if(b%5 != 0) break;
        b /= 5;
    }

    return (b==1?1:2);
}
