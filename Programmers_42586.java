import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
		int sz = progresses.length;
		int i,j;
		int[] arr = new int[sz];
		for(i=0;i<sz;i++) arr[i] = (99-progresses[i]+speeds[i])/speeds[i];
		ArrayList<Integer> ar = new ArrayList<Integer>();
		int cnt = 1;
		for(i=1;i<sz;i++) {
			if(arr[i]<=arr[i-1]) {
				arr[i] = arr[i-1];
				cnt++;
			}else {
				ar.add(cnt);
				cnt = 1;
			}
		}
		ar.add(cnt);
		int[] ans = new int[ar.size()];
		for(i=0;i<ar.size();i++) ans[i] = ar.get(i);
		return ans;
    }
}
