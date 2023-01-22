#include <string>
#include <vector>

using namespace std;

int solution(int p, int q, int k) {
    int answer = 0;
    for(int i=p;i<=q;++i)
    {
        int iTemp = i;
        while(iTemp)
        {
            if(iTemp%10 == k)
            {
                ++answer;
            }
            iTemp /= 10;
        }
    }
    return answer;
}
