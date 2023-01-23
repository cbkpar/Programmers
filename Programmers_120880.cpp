#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    bool bExist[10001] = {false,};
    for(int iNum : numlist)
    {
        bExist[iNum] = true;
    }
    if(bExist[n]) answer.push_back(n);
    for(int i=1;i<10000;++i)
    {
        if(n+i<=10000 && bExist[n+i]) answer.push_back(n+i);
        if(n-i>=0 && bExist[n-i]) answer.push_back(n-i);
    }
    return answer;
}
