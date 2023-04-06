#include <string>
#include <vector>

using namespace std;

void hanoi(vector<vector<int>>& vecAns, int iN, int iStart, int iDest)
{
    if(iN == 1)
    {
        vecAns.push_back({iStart,iDest});
        return;
    }
    hanoi(vecAns, iN-1, iStart, 6-iStart-iDest);
    vecAns.push_back({iStart,iDest});
    hanoi(vecAns,iN-1,6-iStart-iDest,iDest);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(answer, n, 1, 3);
    return answer;
}
