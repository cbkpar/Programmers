class Solution {
    public int solution(int[] nums) {
        int i,j,k,sz,ans;
		sz = nums.length;
		boolean[] isprime = new boolean[3001];
		for(i=2;i*i<=3000;i++) {
			for(j=i*i;j<=3000;j+=i) {
				isprime[j] = true;
			}
		}
		ans = 0;
		for(i=0;i<sz-2;i++) {
			for(j=i+1;j<sz-1;j++) {
				for(k=j+1;k<sz;k++) {
					if(!isprime[nums[i]+nums[j]+nums[k]]) ans++;
				}
			}
		}
        return ans;
    }
}
