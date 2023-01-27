#include <string>
#include <vector>

using namespace std;

int DateToInt(string strDate)
{
    int iYear = 0;
    int iMonth = 0;
    int iDay = 0;
    for(int i=0;i<4;++i)
    {
        iYear *= 10;
        iYear += strDate[i]-'0';
    }
    for(int i=5;i<7;++i)
    {
        iMonth *= 10;
        iMonth += strDate[i]-'0';
    }
    for(int i=8;i<10;++i)
    {
        iDay *= 10;
        iDay += strDate[i]-'0';
    }
    return iYear * 12 * 28 + iMonth * 28 + iDay;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int iDay = DateToInt(today);
    int arrMonth[26] = {0,};
    for(string strTerm : terms)
    {
        int iLength = strTerm.length();
        for(int i=2;i<iLength;++i)
        {
            arrMonth[strTerm[0]-'A'] *= 10;
            arrMonth[strTerm[0]-'A'] += strTerm[i]-'0';       
        }
    }
    int iIndex = 1;
    for(string strPrivacy : privacies)
    {
        int iStart = DateToInt(strPrivacy.substr(0,10));
        int iAdd = arrMonth[strPrivacy[11]-'A'] * 28;
        if(iStart + iAdd <= iDay)
        {
            answer.push_back(iIndex);
        }
        ++iIndex;
    }
    return answer;
}
