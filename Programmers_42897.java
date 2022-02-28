class Solution {
    public int solution(int[] money) {
        int sz = money.length;
        int mx = 0;
        int[][] dp = new int[sz][2];
        dp[1][1] = dp[1][0] = money[0];
        for (int i = 2; i < sz - 1; i++) {
            dp[i][1] = dp[i - 1][0] + money[i];
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
        }
        mx = Math.max(dp[sz - 2][0], dp[sz - 2][1]);
        for (int i = 1; i < sz; i++) {
            dp[i][1] = dp[i - 1][0] + money[i];
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
        }
        mx = Math.max(mx, dp[sz - 1][0]);
        mx = Math.max(mx, dp[sz - 1][1]);
        return mx;
    }
}
