#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int iSize = 0;
int iAns = 1000000000;
vector<int> vecType;

void dfs(int dia, int iron, int stone, int n, int iSum)
{
    if(n>=iSize || (dia+iron+stone == 0))
    {
        iAns = min(iAns, iSum);
        return;
    }
    if(dia)
    {
        int iTemp = 0;
        for(int i=n;i<n+5;++i)
        {
            ++iTemp;
            if(i==iSize-1) break;
        }
        dfs(dia-1,iron,stone,n+5,iSum+iTemp);   
    }
    if(iron)
    {
        int iTemp = 0;
        for(int i=n;i<n+5;++i)
        {
            if(vecType[i]==1) iTemp += 5;
            if(vecType[i]==2) iTemp += 1;
            if(vecType[i]==3) iTemp += 1;
            if(i==iSize-1) break;
        }
        dfs(dia,iron-1,stone,n+5,iSum+iTemp);   
    }
    if(stone)
    {
        int iTemp = 0;
        for(int i=n;i<n+5;++i)
        {
            if(vecType[i]==1) iTemp += 25;
            if(vecType[i]==2) iTemp += 5;
            if(vecType[i]==3) iTemp += 1;
            if(i==iSize-1) break;
        }
        dfs(dia,iron,stone-1,n+5,iSum+iTemp);   
    }
    return;
}

int solution(vector<int> picks, vector<string> minerals) {
    for(string str : minerals)
    {
        if(str == "diamond") vecType.push_back(1);
        if(str == "iron") vecType.push_back(2);
        if(str == "stone") vecType.push_back(3);
    }
    iSize = vecType.size();
    dfs(picks[0],picks[1],picks[2],0,0);
    return iAns;
}
