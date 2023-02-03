#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = -1;
    int iArrAns[5] = {0,};
    int iArrCount[5] = {0,};
    
    int iSize = word.length();
    for(int i=0;i<iSize;++i)
    {
        if(word[i]=='A') iArrAns[i] = 1;
        if(word[i]=='E') iArrAns[i] = 2;
        if(word[i]=='I') iArrAns[i] = 3;
        if(word[i]=='O') iArrAns[i] = 4;
        if(word[i]=='U') iArrAns[i] = 5;
    }
    
    while(true)
    {
        ++answer;
        for(int i=0;i<5;++i)
        {
            if(iArrCount[i]!=iArrAns[i]) break;
            if(i==4) return answer;
        }
        if(iArrCount[0]==0)
        {
            ++iArrCount[0];
        }        
        else if(iArrCount[1]==0)
        {
            ++iArrCount[1];
        }
        else if(iArrCount[2]==0)
        {
            ++iArrCount[2];
        }
        else if(iArrCount[3]==0)
        {
            ++iArrCount[3];
        }
        else
        {
            ++iArrCount[4];
        }
        for(int i=4;i>=0;--i)
        {
            if(iArrCount[i]==6)
            {
                iArrCount[i] = 0;
                ++iArrCount[i-1];
            }
        }
    }
    return answer;
}
