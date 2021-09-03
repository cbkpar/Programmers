class Solution {
    public int solution(String s) {
		int sz,ans,i,j;
		ans = sz = s.length();
		for(i=1;i<=sz/2;i++) {
			int tmp = sz;
			int cnt = 1;
			for(j=i;j<=sz-i;j+=i) {
				if(s.substring(j-i, j).equals(s.substring(j, j+i))) {
					tmp -= i;
					cnt ++;
				}else {
					if(cnt==1) continue;
					while(cnt>0) {
						tmp++;
						cnt/=10;
					}
                    cnt = 1;
				}
			}
			if(cnt!=1) {
				while(cnt>0) {
					tmp++;
					cnt/=10;
				}
			}
			ans = Math.min(ans, tmp);
		}
		return ans;
    }
}
