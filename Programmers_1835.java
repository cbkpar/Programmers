import java.util.*;

class Solution {
    
	static boolean[] chk = new boolean[8];
	static int[] arr = new int[8];
	static int[][] criteria;
	static int sz,ans;
    
    public int solution(int n, String[] data) {
		sz = n;
		criteria = new int[n][4];
		HashMap<Character,Integer> map = new HashMap<>();
		map.put('A',0);
		map.put('C',1);
		map.put('F',2);
		map.put('J',3);
		map.put('M',4);
		map.put('N',5);
		map.put('R',6);
		map.put('T',7);
		for(int i=0;i<n;i++) {
			criteria[i][0] = map.get(data[i].charAt(0));
			criteria[i][1] = map.get(data[i].charAt(2));
			if(data[i].charAt(3)=='=') {
				criteria[i][2] = 0;
			}else if(data[i].charAt(3)=='>') {
				criteria[i][2] = 1;
			}else {
				criteria[i][2] = 2;
			}
			criteria[i][3] = data[i].charAt(4)-'0';
		}
		ans = 0;
		dfs(0);
        return ans;
    }
    
    public static void dfs(int k) {
		if(k==8) {
			int i;
			for(i=0;i<sz;i++) {
				int p = arr[criteria[i][0]];
				int q = arr[criteria[i][1]];
				if(criteria[i][2]==0) {
					if(Math.abs(p-q)-1!=criteria[i][3]) break;
				}else if(criteria[i][2]==1) {
					if(Math.abs(p-q)-1<=criteria[i][3]) break;
				}else {
					if(Math.abs(p-q)-1>=criteria[i][3]) break;
				}
			}
			if(i==sz) ans++;
			return;
		}
		for(int i=0;i<8;i++) {
			if(chk[i]) continue;
			chk[i] = true;
			arr[i] = k;
			dfs(k+1);
			chk[i] = false;
		}
	}
}
