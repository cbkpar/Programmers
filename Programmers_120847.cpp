#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int iFirst = 0;
    int iSecond = 0;
    for(int iNum : numbers)
    {
        if(iNum >= iFirst)
        {
            iSecond = iFirst;
            iFirst = iNum;
        }
        else if(iNum > iSecond)
        {
            iSecond = iNum;
        }
    }
    return iFirst * iSecond;
}
