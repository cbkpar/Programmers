#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dR[4] = {-1,0,1,0};
int dC[4] = {0,-1,0,1};
bool matVisited[100][100] = {false,};

int solution(vector<vector<int> > maps)
{
    int iCount = 0;
    int iR = maps.size();
    int iC = maps[0].size();
    queue<pair<int, int>> qPos;
    qPos.push({0,0});
    matVisited[0][0] = true;
    
    while(qPos.size()>0)
    {
        ++iCount;
        int iSize = qPos.size();
        while(iSize--)
        {
            pair<int, int> p = qPos.front();
            qPos.pop();
            if(p.first == iR-1 && p.second == iC-1)
            {
                return iCount;
            }
            for(int i=0;i<4;++i)
            {
                int iNowR = p.first + dR[i];
                int iNowC = p.second + dC[i];
                if(iNowR < 0 || iNowR > iR-1 || iNowC < 0 || iNowC > iC-1) continue;
                if(matVisited[iNowR][iNowC]) continue;
                matVisited[iNowR][iNowC] = true;
                if(maps[iNowR][iNowC] == 1)
                {
                    qPos.push({iNowR, iNowC});
                }
            }
        }
    }
    
    return -1;
}
