#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int iCount = 0;
    for(char ch : s)
    {
        if(ch == '(')
        {
            ++iCount;
        }
        else
        {
            if(iCount == 0) return false;
            --iCount;
        }
    }
    return iCount==0?true:false;
}
