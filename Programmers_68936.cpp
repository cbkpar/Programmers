#include <string>
#include <vector>

using namespace std;

int matDP[1025][1025] = {0,};
int iZero, iOne;

void CalcQuad(int iR, int iC, int iLen)
{
    int iCount = matDP[iR+iLen-1][iC+iLen-1];
    if(iR > 0) iCount -= matDP[iR-1][iC+iLen-1];
    if(iC > 0) iCount -= matDP[iR+iLen-1][iC-1];
    if(iR > 0 && iC > 0) iCount += matDP[iR-1][iC-1];
    if(iCount == 0)
    {
        ++iZero;
        return;
    }
    if(iCount == iLen * iLen)
    {
        ++iOne;
        return;
    }
    CalcQuad(iR, iC, iLen/2);
    CalcQuad(iR + iLen/2, iC, iLen/2);
    CalcQuad(iR, iC + iLen/2, iLen/2);
    CalcQuad(iR + iLen/2, iC + iLen/2, iLen/2);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int iSize = arr.size();
    for(int i=0;i<iSize;++i)
    {
        for(int j=0;j<iSize;++j)
        {
            if(i>0) matDP[i][j] += matDP[i-1][j];
            if(j>0) matDP[i][j] += matDP[i][j-1];
            if(i>0&&j>0) matDP[i][j] -= matDP[i-1][j-1];
            matDP[i][j] += arr[i][j];
        }
    }
    iZero = iOne = 0;
    CalcQuad(0,0,iSize);
    answer.push_back(iZero);
    answer.push_back(iOne);
    return answer;
}
