#include <iostream>
#include <string>

using namespace std;

char ArrWord[5001];
int ArrCount[5001] = {0,};

int solution(string s)
{
    int answer = 1;
    int iSize = s.length();
    for(int i=0;i<=5000;++i) ArrWord[i] = '#';
    for(int i=0;i<iSize;++i) ArrWord[i*2+1] = s[i];
    
    int iR = 0;
    int iP = 0;
    
    for(int i=0;i<iSize*2+1;++i)
    {
        if(i <= iR)
        {
            ArrCount[i] = ArrCount[2*iP-i]<iR-i?ArrCount[2*iP-i]:iR-i;
        }
        else
        {
            ArrCount[i] = 0;
        }
        while(i-ArrCount[i]-1>=0&&i+ArrCount[i]+1<iSize*2+1&&ArrWord[i-ArrCount[i]-1]==ArrWord[i+ArrCount[i]+1])
        {
            ++ArrCount[i];
        }
        if(iR < i+ArrCount[i])
        {
            iR = i + ArrCount[i];
            iP = i;
        }
    }
    for(int i=0;i<iSize*2+1;++i)
    {
        if(answer < ArrCount[i])
        {
            answer = ArrCount[i];
        }
    }
    return answer;
}
