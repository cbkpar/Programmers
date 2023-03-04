#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int iIndex1 = 0;
    int iIndex2 = 0;
    int iSize1 = cards1.size();
    int iSize2 = cards2.size();
    for(string str : goal)
    {
        if(iIndex1 < iSize1 && cards1[iIndex1] == str)
        {
            ++iIndex1;
            continue;
        }
        if(iIndex2 < iSize2 && cards2[iIndex2] == str)
        {
            ++iIndex2;
            continue;
        }
        return "No";
    }
    return "Yes";
}
