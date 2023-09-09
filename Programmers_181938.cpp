#include <string>
#include <vector>

using namespace std;

int CalcAB(int iA, int iB)
{
    vector<int> vecA;
    vector<int> vecB;
    while(iA>0)
    {
        vecA.push_back(iA%10);
        iA /= 10;
    }
    while(iB>0)
    {
        vecB.push_back(iB%10);
        iB /= 10;
    }

    int iSizeA = vecA.size();
    int iSizeB = vecB.size();

    int iTempAB = 0;
    int iTempBA = 0;
    for(int i=iSizeA-1;i>=0;--i)
    {
        iTempAB *= 10;
        iTempAB += vecA[i];
    }
    for(int i=iSizeB-1;i>=0;--i)
    {
        iTempAB *= 10;
        iTempAB += vecB[i];
    }
    return iTempAB;
}
int solution(int a, int b) {
    return max(CalcAB(a,b), 2*a*b);
}
