#include <string>
#include <vector>

using namespace std;

int ArrIndex[12] = {0,};
int iN, iCount;

void BackTracking(int k)
{
    for(int i=k-2;i>=0;--i)
    {
        int iDiff = ArrIndex[k-1]-ArrIndex[i];
        if(iDiff == 0 || iDiff == k-i-1 || iDiff == -k+i+1) return;
    }
    if(k==iN)
    {
        ++iCount;
        return;
    }
    for(int i=0;i<iN;++i)
    {
        ArrIndex[k] = i;
        BackTracking(k+1);
    }
}

int solution(int n) {
    iN = n;
    iCount = 0;
    BackTracking(0);
    return iCount;
}
