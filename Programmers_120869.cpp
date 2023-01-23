#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int arrCount[26] = {0,};
    int iLen = spell.size();
    for(int i=0;i<iLen;++i)
    {
        ++arrCount[spell[i][0]-'a'];
    }
    for(string strWord : dic)
    {
        if(strWord.length() == iLen)
        {
            int arrTempCount[26] = {0,};
            for(int i=0;i<iLen;++i)
            {
                ++arrTempCount[strWord[i]-'a'];
            }
            for(int i=0;i<26;++i)
            {
                if(arrCount[i] != arrTempCount[i])
                {
                    break;
                }
                if(i==25)
                {
                    return 1;
                }
            }
        }
    }
    return 2;
}
