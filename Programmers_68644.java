import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        boolean[] chk = new boolean[201];
		int sz,i,j;
		sz = numbers.length;
		for(i=0;i<sz-1;i++) {
			for(j=i+1;j<sz;j++) {
				chk[numbers[i]+numbers[j]] = true;
			}
		}
		ArrayList<Integer> arr = new ArrayList<>();
		for(i=0;i<=200;i++) if(chk[i]) arr.add(i);
		int[] ans = new int[arr.size()];
		for(i=0;i<arr.size();i++) ans[i] = arr.get(i);
		return ans;
    }
}
