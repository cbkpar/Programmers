#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int a, int b, int c, int d) {
    vector<int> vecNum(4,0);
    vecNum[0] = a;
    vecNum[1] = b;
    vecNum[2] = c;
    vecNum[3] = d;
    sort(vecNum.begin(), vecNum.end());
    if(vecNum[0]==vecNum[1]&&vecNum[1]==vecNum[2]&&vecNum[2]==vecNum[3])
    {
        return vecNum[0]*1111;
    }
    
    if(vecNum[0]==vecNum[1]&&vecNum[1]==vecNum[2])
    {
        return (vecNum[0]*10+vecNum[3])*(vecNum[0]*10+vecNum[3]);
    }
    if(vecNum[1]==vecNum[2]&&vecNum[2]==vecNum[3])
    {
        return (vecNum[3]*10+vecNum[0])*(vecNum[3]*10+vecNum[0]);
    }
    
    if(vecNum[0]==vecNum[1]&&vecNum[2]==vecNum[3])
    {
        return (vecNum[2]+vecNum[1])*(vecNum[2]-vecNum[1]);
    }
    if(vecNum[0]==vecNum[1])
    {
        return vecNum[2]*vecNum[3];
    }
    if(vecNum[1]==vecNum[2])
    {
        return vecNum[0]*vecNum[3];
    }
    if(vecNum[2]==vecNum[3])
    {
        return vecNum[0]*vecNum[1];
    }
    
    return vecNum[0];
}
