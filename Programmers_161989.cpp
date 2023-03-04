#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int iIndex = 0;
    int iSize = section.size();
    while(iIndex<iSize)
    {
        ++answer;
        int iMax = section[iIndex]+m;
        while(iIndex<iSize)
        {
            if(section[iIndex]>=iMax) break;
            ++iIndex;
        }
    }
    return answer;
}
