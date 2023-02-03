#include <string>
#include <vector>

using namespace std;

int iArrCount[1451] = {0,};

int DateToInt(string strDate)
{
    int iValue = 0;
    iValue += ((strDate[0]-'0') * 10 + (strDate[1]-'0')) * 60;
    iValue += (strDate[3]-'0') * 10 + (strDate[4]-'0');
    return iValue;
}
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    for(vector<string> vecDate : book_time)
    {
        int iStart = DateToInt(vecDate[0]);
        int iEnd = DateToInt(vecDate[1]) + 10;
        ++iArrCount[iStart];
        --iArrCount[iEnd];
    }
    for(int i=1;i<=1440;++i)
    {
        iArrCount[i] += iArrCount[i-1];
    }
    int iMax = 0;
    for(int i=0;i<=1440;++i)
    {
        if(iMax < iArrCount[i])
        {
            iMax = iArrCount[i];
        }
    }
    answer = iMax;
    return answer;
}
