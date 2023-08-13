#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    int iLen = rny_string.length();
    int iNewLen = iLen;
    for(int i=0;i<iLen;++i)
    {
        if(rny_string[i]=='m')
        {
            ++iNewLen;
        }
    }
    
    string answer = "";
    answer.resize(iNewLen);
    int iIndex = 0;
    
    for(int i=0;i<iLen;++i)
    {
        if(rny_string[i]=='m')
        {
            answer[iIndex++] = 'r';
            answer[iIndex++] = 'n';
        }
        else
        {
            answer[iIndex++] = rny_string[i];
        }
    }
    return answer;
}
