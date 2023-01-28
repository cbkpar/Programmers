#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    int iAnsIndex = -1;
    int iMaxScore = 1;
    int arrCount[11] = {0,};
    int arrTemp[11] = {0,};
    arrCount[10] = -1;
    for(int i=0;i<(1<<10);++i)
    {
        int iCount = 0;
        int iScore = 0;
        for(int j=0;j<10;++j)
        {
            if((i&(1<<j))==(1<<j))
            {
                iCount += info[9-j] + 1;
                arrTemp[9-j] = info[9-j] + 1;
                iScore += j+1;
            }
            else
            {
                arrTemp[9-j] = 0;
                if(info[9-j] > 0)
                {
                    iScore -= j+1;
                }
            }
        }
        if(iCount <= n)
        {
            if(iScore > iMaxScore)
            {
                iMaxScore = iScore;
                iAnsIndex = i;
                arrTemp[10] = n - iCount;
                for(int k=0;k<11;++k)
                {
                    arrCount[k] = arrTemp[k];
                }
            }
            else if(iScore == iMaxScore)
            {
                arrTemp[10] = n - iCount;
                for(int j=10;j>=0;--j)
                {
                    if(arrTemp[j]==arrCount[j]) continue;
                    if(arrTemp[j]<arrCount[j]) break;
                    for(int k=0;k<11;++k)
                    {
                        arrCount[k] = arrTemp[k];
                    }
                    iAnsIndex = i;
                    break;
                }
            }
        }
    }
    if(iAnsIndex == -1)
    {
        answer.push_back(-1);
    }
    else
    {
        for(int i=0;i<11;++i)
        {
            answer.push_back(arrCount[i]);
        }
    }
    return answer;
}
