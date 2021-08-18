import java.util.*;
import java.io.*;

class Solution {
    public int solution(int n, int[][] computers) {
		int i,j,ans,sz,com;
		boolean[] chk = new boolean[n];
		ArrayList<Integer>[] node = new ArrayList[n];
		for(i=0;i<n;i++) node[i] = new ArrayList<Integer>();
		for(i=0;i<n;i++) for(j=0;j<n;j++) if(computers[i][j]==1) node[i].add(j);
		ans = 0;
		for(i=0;i<n;i++) {
			if(!chk[i]) {
				ans++;
				Queue<Integer> q = new LinkedList<>();
				q.add(i);
				chk[i] = true;
				while(!q.isEmpty()) {
					com = q.poll();
					sz = node[com].size();
					for(j=0;j<sz;j++) {
						if(!chk[node[com].get(j)]) {
							chk[node[com].get(j)] = true;
							q.add(node[com].get(j));
						}
					}
				}
				
			}
		}
        return ans;
    }
}
