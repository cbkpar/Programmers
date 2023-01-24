#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector<pair<int, int>> vecRank;
    int iSize = emergency.size();
    for(int i=0;i<iSize;++i)
    {
        vecRank.push_back({emergency[i],i});
    }
    sort(vecRank.begin(), vecRank.end());
    answer.resize(iSize);
    int iRank = 1;
    for(int i=iSize-1;i>=0;--i)
    {
        answer[vecRank[i].second] = iRank++;
    }
    return answer;
}
