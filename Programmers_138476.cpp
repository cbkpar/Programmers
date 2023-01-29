#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ArrCount[100001] = {0,};

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(),tangerine.end());
    int iSize = tangerine.size();
    int iCount = 1;
    for(int i=1;i<iSize;++i)
    {
        if(tangerine[i] != tangerine[i-1])
        {
            ++ArrCount[iCount];
            iCount = 1;
        }
        else
        {
            ++iCount;
        }
    }
    ++ArrCount[iCount];
    iCount = 1;
    for(int i=100000;i>0;--i)
    {
        while(ArrCount[i]--)
        {
            if(k>0)
            {
                k -= i;
                ++answer;
            }
        }
        if(k <= 0) break;
    }

    return answer;
}
