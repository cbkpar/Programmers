#include <string>
#include <vector>

using namespace std;

bool bArrUsed[21] = {false,};

vector<int> solution(int n, long long k) {
    vector<int> answer;
    --k;
    long long lFact = 1;
    for(int i=2;i<n;++i)
    {
        lFact *= i;
    }
    for(int i=0;i<n;++i)
    {
        int iNum = (int)(k/lFact);
        k%=lFact;
        int iCount = 0;
        for(int j=0;j<n;++j)
        {
            if(!bArrUsed[j])
            {
                if(iCount == iNum)
                {
                    answer.push_back(j+1);
                    bArrUsed[j] = true;
                    break;
                }
                ++iCount;
            }
        }
        if(n-i-1 != 0) lFact /= n-i-1;
    }
    
    return answer;
}
