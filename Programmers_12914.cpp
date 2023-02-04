#include <string>
#include <vector>

using namespace std;

long long ArrCount[2001] = {0,};

long long solution(int n) {
    ArrCount[1] = 1;
    ArrCount[2] = 2;
    for(int i=3;i<=2000;++i)
    {
        ArrCount[i] = (ArrCount[i-1]+ArrCount[i-2])%1234567;
    }
    return ArrCount[n];
}
