import java.util.*;
import java.io.*;

class Solution {
    public int solution(int n, int s, int a, int b, int[][] fares) {
		int i,j,k,sz,p,q,c,ans;
		int[][] cost = new int[n+1][n+1];
		for(i=1;i<=n;i++) Arrays.fill(cost[i],700000000);
        for(i=1;i<=n;i++) cost[i][i] = 0;
		sz = fares.length;
		for(i=0;i<sz;i++) {
			p = fares[i][0];
			q = fares[i][1];
			c = fares[i][2];
			cost[p][q] = c;
			cost[q][p] = c;
		}
		for(k=1;k<=n;k++) {
			for(i=1;i<=n;i++) {
				for(j=1;j<=n;j++) {
					if(i==j) continue;
					if(cost[i][j]>cost[i][k]+cost[k][j]) cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
		ans = Integer.MAX_VALUE;
		for(i=1;i<=n;i++) ans = Math.min(ans, cost[s][i]+cost[i][a]+cost[i][b]);
        return ans;
    }
}
