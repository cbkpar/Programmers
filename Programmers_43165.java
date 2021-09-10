class Solution {
    public int solution(int[] numbers, int target) {
		int sz = numbers.length;
		int[][] dp = new int[sz+1][40001];
		dp[0][20000] = 1;
		int i,j,t;
		for(i=0;i<sz;i++) {
			t = numbers[i];
			for(j=0;j<=40000;j++) {
				if(j+t<=40000) dp[i+1][j] += dp[i][j+t]; 
				if(j-t>=0) dp[i+1][j] += dp[i][j-t]; 
			}
		}
		return dp[sz][20000+target];
    }
}
