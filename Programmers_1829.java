import java.util.*;

class Solution {
    public int[] solution(int m, int n, int[][] picture) {
		int[] dy = {-1,0,1,0};
		int[] dx = {0,-1,0,1};
		int i,j,k;
		boolean[][] chk = new boolean[m][n];
		int[] ans = new int[2];
		Queue<pos> q = new LinkedList<>();
		for(i=0;i<m;i++) {
			for(j=0;j<n;j++) {
				if(!chk[i][j]) {
					chk[i][j] = true;
					int t = picture[i][j];
					if(t!=0) {
						q.add(new pos(i,j));
						ans[0]++;
					}
					int cnt = 1;
					while(!q.isEmpty()) {
						pos p = q.poll();
						for(k=0;k<4;k++) {
							int ny = p.y + dy[k];
							int nx = p.x + dx[k];
							if(ny<0||ny>m-1||nx<0||nx>n-1) continue;
							if(chk[ny][nx]||picture[ny][nx]!=t) continue;
							chk[ny][nx] = true;
							cnt++;
							q.add(new pos(ny,nx));
						}
					}
					ans[1] = Math.max(ans[1], cnt);
				}
			}
		}
        return ans;
    }
}

class pos {
	int y,x;
	public pos(int y, int x) {
		this.y = y;
		this.x = x;
	}
}
