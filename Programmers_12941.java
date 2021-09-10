import java.util.*;

class Solution
{
    public int solution(int []A, int []B) {
		Arrays.sort(A);
		Arrays.sort(B);
		int sz = A.length;
		int ans = 0;
		for(int i=0;i<sz;i++) ans += A[i]*B[sz-i-1];
		System.out.println(ans);
        return ans;
    }
}
