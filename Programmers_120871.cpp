#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    while(true)
    {
        ++answer;
        int iTemp = answer;
        bool bPossible = true;
        if(iTemp%3==0) bPossible = false;
        while(iTemp)
        {
            int iNum = iTemp%10;
            if(iNum==3)
            {
                bPossible = false;
                break;
            }
            iTemp /= 10;
        }
        if(bPossible)
        {
            --n;
            if(n==0) break;
        }
    }
    return answer;
}
