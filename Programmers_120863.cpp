#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    int iFirst = 0;
    int iSecond = 0;
    
    int iTemp = 0;
    bool bIsX = false;
    for(char ch : polynomial)
    {
        if(ch >= '0' && ch <= '9')
        {
            iTemp *= 10;
            iTemp += ch - '0';
        }
        else if(ch == 'x')
        {
            bIsX = true;
        }
        else if(ch == '+')
        {
            if(iTemp == 0)
            {
                iTemp = 1;
            }
            if(bIsX)
            {
                iFirst += iTemp;
                bIsX = false;
            }
            else
            {
                iSecond += iTemp;
            }
            iTemp = 0;
        }
    }
    if(iTemp == 0)
    {
        iTemp = 1;
    }
    if(bIsX)
    {
        iFirst += iTemp;
        bIsX = false;
    }
    else
    {
        iSecond += iTemp;
    }
    
    if(iFirst > 1)
    {
        answer = to_string(iFirst) + "x";
        if(iSecond != 0) answer += " + " + to_string(iSecond);
    }
    else if(iFirst == 1)
    {
        answer = "x";
        if(iSecond != 0) answer += " + " + to_string(iSecond);
    }
    else
    {
        answer += to_string(iSecond);
    }
    return answer;
}
