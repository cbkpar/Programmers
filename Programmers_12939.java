import java.util.*;

class Solution {
    public String solution(String s) {
		int mi = Integer.MAX_VALUE;
		int mx = Integer.MIN_VALUE;
		int t;
		StringTokenizer st = new StringTokenizer(s);
		while(st.hasMoreTokens()) {
			t = Integer.parseInt(st.nextToken());
			mi = Math.min(mi,t);
			mx = Math.max(mx,t);
		}
        return mi+" "+mx;
    }
}
