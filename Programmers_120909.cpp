#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    long long lLeft = 1;
    long long lRight = n;
    while(lLeft <= lRight)
    {
        long long lMid = (lLeft + lRight)/2;
        if(lMid * lMid > n)
        {
            lRight = lMid - 1;
        }
        else if(lMid * lMid == n)
        {
            return 1;
        }
        else
        {
            lLeft = lMid + 1;
        }
    }
    return 2;
}
