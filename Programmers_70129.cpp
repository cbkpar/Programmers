#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int iCount = 1;
    if(s=="1") iCount = 0;
    int iZero = 0;
    int iSize = 0;
    for(char ch : s)
    {
        if(ch == '0')
        {
            ++iZero;
        }
        else
        {
            ++iSize;
        }
    }
    while(iSize > 1)
    {
        ++iCount;
        int iTemp = iSize;
        iSize = 0;
        while(iTemp)
        {
            if(iTemp%2==0)
            {
                ++iZero;
            }
            else
            {
                ++iSize;
            }
            iTemp /= 2;
        }
    }
    answer.push_back(iCount);
    answer.push_back(iZero);
    return answer;
}
