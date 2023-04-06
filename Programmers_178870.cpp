#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2,0);
    int iLeft = 0;
    int iRight = 0;
    int iSum = sequence[0];
    int iSize = sequence.size();
    int iLen = iSize+1;
    while(iLeft<=iRight && iRight < iSize)
    {
        if(iSum==k)
        {
            if(iRight-iLeft<iLen)
            {
                answer[0] = iLeft;
                answer[1] = iRight;
                iLen = iRight-iLeft;
            }
        }
        if(iSum < k)
        {
            if(iRight+1<iSize) iSum += sequence[iRight+1];
            ++iRight;
        }
        else
        {
            if(iLeft+1<iSize) iSum -= sequence[iLeft];
            ++iLeft;
        }
    }
    return answer;
}
