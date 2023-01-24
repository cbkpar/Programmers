#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    sort(array.begin(), array.end());
    
    vector<pair<int, int>> vecCount;
    
    int iTempCount = 1;
    int iSize = array.size();
    for(int i=1;i<iSize;++i)
    {
        if(array[i-1] == array[i])
        {
            ++iTempCount;
        }
        else
        {
            vecCount.push_back({iTempCount, array[i-1]});
            iTempCount = 1;
        }
    }
    vecCount.push_back({iTempCount, array[iSize-1]});
    sort(vecCount.begin(), vecCount.end(), greater<>());
    
    if(vecCount.size()==1)
    {
        return vecCount[0].second;
    }
    else
    {
        if(vecCount[0].first != vecCount[1].first)
        {
            return vecCount[0].second;
        }
        else
        {
            return -1;
        }
    }
    return -1;
}
