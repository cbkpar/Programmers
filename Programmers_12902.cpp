#include <string>
#include <vector>

using namespace std;

long long dp[5001] = {0,};

int solution(int n) {
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    for(int i=4;i<=n;i+=2)
    {
        dp[i] = 3*dp[i-2];
        for(int j=i-4;j>=0;j-=2)
        {
            dp[i] += 2 * dp[j];
        }
        dp[i] %= 1000000007;
    }
    return (int)dp[n];
}
