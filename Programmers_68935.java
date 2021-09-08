import java.util.*;

class Solution {
    public int solution(int n) {
        Stack<Integer> st = new Stack<>();
		while(n>0) {
			st.add(n%3);
			n/=3;
		}
		int ans = 0;
		int t = 1;
		while(!st.isEmpty()) {
			ans += st.pop()*t;
			t*=3;
		}
        return ans;
    }
}
