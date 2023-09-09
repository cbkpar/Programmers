#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    int iLen = numLog.size();
    answer.resize(iLen-1);
    for(int i=1;i<iLen;++i)
    {
        int iDiff = numLog[i]-numLog[i-1];
        if(iDiff==1) answer[i-1] = 'w';
        if(iDiff==-1) answer[i-1] = 's';
        if(iDiff==10) answer[i-1] = 'd';
        if(iDiff==-10) answer[i-1] = 'a';
    }
    return answer;
}
