#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for(int i=0;i<64;++i)
    {
        int iSum = 0;
        int iTemp = i;
        for(int j=0;j<6;++j)
        {
            iSum *= 10;
            if(iTemp&1)
            {
                iSum += 5;
            }
            iTemp >>= 1;
        }
        if(iSum>=l&&iSum<=r)
        {
            answer.push_back(iSum);
        }
    }
    sort(answer.begin(), answer.end());
    if(answer.size()==0) return {-1};
    return answer;
}
