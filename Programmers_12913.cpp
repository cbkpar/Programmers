#include <iostream>
#include <vector>

#define MAX(a,b) (a)>(b)?(a):(b)

using namespace std;

int matScore[100000][4] = {0,};

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int iSize = land.size();
    for(int i=0;i<4;++i) matScore[0][i] = land[0][i];
    for(int i=1;i<iSize;++i)
    {
        matScore[i][0] = land[i][0] + (MAX(MAX(matScore[i-1][1],matScore[i-1][2]),matScore[i-1][3]));
        matScore[i][1] = land[i][1] + (MAX(MAX(matScore[i-1][2],matScore[i-1][3]),matScore[i-1][0]));
        matScore[i][2] = land[i][2] + (MAX(MAX(matScore[i-1][3],matScore[i-1][0]),matScore[i-1][1]));
        matScore[i][3] = land[i][3] + (MAX(MAX(matScore[i-1][0],matScore[i-1][1]),matScore[i-1][2]));
    }
    for(int i=0;i<4;++i)
    {
        if(answer < matScore[iSize-1][i])
        {
            answer = matScore[iSize-1][i];
        }
    }

    return answer;
}
