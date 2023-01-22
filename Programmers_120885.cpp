#include <string>
#include <vector>

using namespace std;

int BinToNum(string str)
{
    int iTemp = 0;
    int iMultiple = 1;
    int iLen = str.length();
    for(int i=iLen-1;i>=0;--i)
    {
        if(str[i]=='1') iTemp+=iMultiple;
        iMultiple *= 2;
    }
    return iTemp;
}

string NumToBin(int iNum)
{
    string str = "";
    if(iNum == 0) return "0";
    while(iNum)
    {
        str = (char)(iNum%2 +'0') + str;
        iNum /= 2;
    }
    return str;
}

string solution(string bin1, string bin2) {
    string answer = NumToBin(BinToNum(bin1)+BinToNum(bin2));
    return answer;
}
