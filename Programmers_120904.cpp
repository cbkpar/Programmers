#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int iIndex = -1;
    int iCount = 0;
    while(num)
    {
        ++iCount;
        if(num%10 == k)
        {
            iIndex = iCount;
        }
        num /= 10;
    }
    return iIndex==-1?-1:iCount-iIndex+1;
}
