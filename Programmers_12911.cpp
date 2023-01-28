#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int iCount = 0;
    int iIndex = 0;
    bool bFirst = false;
    int iTemp = n;
    while(true)
    {
        if(iTemp%2==0)
        {
            if(bFirst)
            {
                break;
            }
        }
        else
        {
            ++iCount;
            bFirst = true;
        }
        ++iIndex;
        iTemp /= 2;
    }
    answer = (n >> iIndex) << iIndex;
    answer += 1 << iIndex;
    answer += (1 << (iCount-1)) - 1;
    return answer;
}
