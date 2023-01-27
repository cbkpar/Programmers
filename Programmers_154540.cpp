#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int idR[4] = {-1,0,1,0};
int idC[4] = {0,-1,0,1};
bool bVisited[100][100] = {false,};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int iRow = maps.size();
    int iCol = maps[0].length();
    queue<pair<int, int>> qVisit;
    for(int i=0;i<iRow;++i)
    {
        for(int j=0;j<iCol;++j)
        {
            if(bVisited[i][j]) continue;
            bVisited[i][j] = true;
            if(maps[i][j] == 'X') continue;
            qVisit.push({i,j});
            int iSum = 0;
            while(qVisit.size()>0)
            {
                pair<int, int> p = qVisit.front();
                qVisit.pop();
                int iNowR = p.first;
                int iNowC = p.second;
                iSum += maps[iNowR][iNowC] - '0';
                for(int i=0;i<4;++i)
                {
                    int iNextR = iNowR + idR[i];
                    int iNextC = iNowC + idC[i];
                    if(iNextR < 0 || iNextR > iRow-1 || iNextC < 0 || iNextC > iCol-1) continue;
                    if(bVisited[iNextR][iNextC]) continue;
                    bVisited[iNextR][iNextC] = true;
                    if(maps[iNextR][iNextC] != 'X')
                    {
                        qVisit.push({iNextR,iNextC});
                    }
                }
            }
            answer.push_back(iSum);
        }
    }
    
    
    if(answer.size()==0)
    {
        answer.push_back(-1);
    }
    sort(answer.begin(), answer.end());
    return answer;
}
