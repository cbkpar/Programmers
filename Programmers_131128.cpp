#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    int arrCountX[10] = {0,};    
    int arrCountY[10] = {0,};
    
    for(char ch:X)
    {
        ++arrCountX[ch-'0'];
    }
    for(char ch:Y)
    {
        ++arrCountY[ch-'0'];
    }
    
    int iCount = 0;
    int arrCount[10] = {0,};
    for(int i=0;i<=9;++i)
    {
        arrCount[i] = arrCountX[i]<arrCountY[i]?arrCountX[i]:arrCountY[i];
        iCount += arrCount[i];
    }
    if(iCount == 0)
    {
        return "-1";
    }
    if(arrCount[0] == iCount)
    {
        return "0";
    }
    
    answer.resize(iCount);
    int iIndex = 0;
    for(int i=9;i>=0;--i)
    {
        int iTemp = arrCountX[i]<arrCountY[i]?arrCountX[i]:arrCountY[i];
        while(iTemp--)
        {
            answer[iIndex++] = (char)(i+'0');
        }
    }
    return answer;
}
