#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    int iTargetSize = targets.size();
    vector<int> vecKey(26,100000);
    for(string strKey : keymap)
    {
        int iLen = strKey.length();
        for(int i=0;i<iLen;++i)
        {
            vecKey[strKey[i]-'A'] = min(vecKey[strKey[i]-'A'],i+1);
        }
    }
    vector<int> answer(iTargetSize,0);
    for(int i=0;i<iTargetSize;++i)
    {
        int iCount = 0;
        for(char ch : targets[i])
        {
            iCount += vecKey[ch-'A'];
        }
        if(iCount >= 100000)
        {
            answer[i] = -1;
        }
        else
        {
            answer[i] = iCount;
        }
    }

    return answer;
}
