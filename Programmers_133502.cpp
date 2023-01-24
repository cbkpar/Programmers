#include <string>
#include <vector>

using namespace std;

int arrIndex[1000000] = {0,};

int solution(vector<int> ingredient) {
    int answer = 0;
    int iIndex = 0;
    for(int iNum : ingredient)
    {
        arrIndex[iIndex] = iNum;
        if(iNum == 1 && iIndex >= 3)
        {
            if(arrIndex[iIndex-3] == 1 && arrIndex[iIndex-2] == 2 && arrIndex[iIndex-1] == 3)
            {
                ++answer;
                iIndex-=3;
            }
            else
            {
                ++iIndex;
            }
        }
        else
        {
            ++iIndex;
        }
    }
    return answer;
}
