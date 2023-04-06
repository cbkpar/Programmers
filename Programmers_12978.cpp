#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 1;

    vector<vector<int>> matCost(N+1, vector<int>(N+1,500001));
    for(vector<int> vecRoad : road)
    {
        matCost[vecRoad[0]][vecRoad[1]] = min(matCost[vecRoad[0]][vecRoad[1]], vecRoad[2]);
        matCost[vecRoad[1]][vecRoad[0]] = min(matCost[vecRoad[1]][vecRoad[0]], vecRoad[2]);
    }
    for(int k=1;k<=N;++k)
    {
        for(int i=1;i<=N;++i)
        {
            for(int j=1;j<=N;++j)
            {
                if(i==j) continue;
                if(matCost[i][j] > matCost[i][k] + matCost[k][j])
                {
                    matCost[i][j] = matCost[i][k] + matCost[k][j];
                }
            }
        }
    }
    for(int i=2;i<=N;++i)
    {
        if(matCost[1][i] <= K) ++answer;
    }
    return answer;
}
