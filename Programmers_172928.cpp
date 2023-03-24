#include <string>
#include <vector>

using namespace std;

int dR[4] = {-1,1,0,0};
int dC[4] = {0,0,-1,1};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer(2,0);
    int iR = park.size();
    int iC = park[0].length();
    
    pair<int, int> Pos = {0, 0};
    for(int i=0;i<iR;++i)
    {
        for(int j=0;j<iC;++j)
        {
            if(park[i][j] == 'S') Pos = {i,j};
        }
    }
    
    for(string strCommand : routes)
    {
        int iDir = -1;
        int iCount = strCommand[2] - '0';
        if(strCommand[0] == 'N') iDir = 0;
        if(strCommand[0] == 'S') iDir = 1;
        if(strCommand[0] == 'W') iDir = 2;
        if(strCommand[0] == 'E') iDir = 3;
        
        bool bMove = true;
        
        pair<int,int> TempPos = Pos;
        while(iCount--)
        {
            TempPos.first += dR[iDir];
            TempPos.second += dC[iDir];
            if(TempPos.first < 0 || TempPos.first > iR-1 ||
               TempPos.second < 0 || TempPos.second > iC-1 || park[TempPos.first][TempPos.second] == 'X')
            {
                bMove = false;
                break;
            }
        }
        
        if(bMove) Pos = TempPos;
    }
    answer[0] = Pos.first;
    answer[1] = Pos.second;
    return answer;
}
