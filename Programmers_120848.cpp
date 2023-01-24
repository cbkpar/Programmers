#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int iTemp = 1;
    int iLevel = 1;
    while(true)
    {
        if(iTemp * (iLevel + 1) > n)
        {
            break;
        }
        ++iLevel;
        iTemp *= iLevel;
    }
    return iLevel;
}
