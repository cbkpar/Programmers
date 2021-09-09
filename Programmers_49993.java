class Solution {
    public int solution(String skill, String[] skill_trees) {
		int sz,i,j,ans,cnt,t,tsz;
		int[] arr = new int[26];
		sz = skill.length();
		for(i=0;i<sz;i++) arr[skill.charAt(i)-'A'] = i+1;
		ans = 0;
		for(String str:skill_trees) {
			tsz = str.length();
			cnt = 1;
			for(i=0;i<tsz;i++) {
				t = arr[str.charAt(i)-'A'];
				if(t==0) continue;
				if(t==cnt) {
					cnt++;
				}else {
					break;
				}
			}
			if(i==tsz) ans++;
		}
        return ans;
    }
}
