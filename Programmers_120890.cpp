#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    bool bExist[101] = {false,};
    for(int iNum : array)
    {
        bExist[iNum] = true;
    }
    for(int i=0;i<100;++i)
    {
        if(n-i>0 && bExist[n-i]) return n-i;
        if(n+i<=100 && bExist[n+i]) return n+i;
    }
    return -1;
}
