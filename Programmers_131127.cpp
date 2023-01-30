#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> mapIndex;
    int iLen = want.size();
    for(int i=0;i<iLen;++i) mapIndex[want[i]] = i;
    int iCount = number.size();
    int iSize = discount.size();
    for(int i=0;i<10;++i)
    {
        if(mapIndex.find(discount[i]) == mapIndex.end()) continue;
        if(--number[mapIndex[discount[i]]] == 0)
        {
            --iCount;
        }
        if(iCount == 0) ++answer;
    }
    for(int i=10;i<iSize;++i)
    {
        if(mapIndex.find(discount[i]) != mapIndex.end())
        {
            if(--number[mapIndex[discount[i]]] == 0)
            {
                --iCount;
            }
        }
        if(mapIndex.find(discount[i-10]) != mapIndex.end())
        {
            if(number[mapIndex[discount[i-10]]]++ == 0)
            {
                ++iCount;
            }
        }
        if(iCount == 0) ++answer;
    }
    return answer;
}
