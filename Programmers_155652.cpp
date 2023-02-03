#include <string>
#include <vector>

using namespace std;

bool arrWord[26] = {false,};
char arrChar[26];
int arrIndex[26] = {0,};

string solution(string s, string skip, int index) {
    string answer = "";
    int iSize = skip.length();
    for(char ch:skip)
    {
        arrWord[ch-'a'] = true;
    }
    int iCount = 0;
    for(int i=0;i<26;++i)
    {
        if(!arrWord[i])
        {
            arrIndex[i] = iCount;
            arrChar[iCount++] = (char)(i+'a');
        }
    }
    int iLen = s.length();
    answer.resize(iLen);
    for(int i=0;i<iLen;++i)
    {
        answer[i] = (char)arrChar[(arrIndex[s[i]-'a']+index)%iCount];
    }
    return answer;
}
