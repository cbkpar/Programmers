#include <string>
using namespace std;

bool matVisited[121][121] = {false,};

int solution(string dirs) {
    int answer = 0;
    int iR = 5;
    int iC = 5;
    for(char ch : dirs)
    {
        int iNextR = iR;
        int iNextC = iC;
        switch(ch)
        {
            case 'L': --iNextC; break;
            case 'R': ++iNextC; break;
            case 'U': ++iNextR; break;
            case 'D': --iNextR; break;
        }
        if(iNextR < 0 || iNextR > 10 || iNextC < 0 || iNextC > 10) continue;
        int iIndex = iR * 11 + iC;
        int iNextIndex = iNextR * 11 + iNextC;
        if(!matVisited[iIndex][iNextIndex])
        {
            ++answer;
            matVisited[iIndex][iNextIndex] = true;
            matVisited[iNextIndex][iIndex] = true;
        }
        iR = iNextR;
        iC = iNextC;
    }
    return answer;
}
