import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(String[] gems) {
        HashSet<String> set = new HashSet<>();
        for(String str:gems) if(!set.contains(str)) set.add(str);
		int sz = gems.length;
		int msz = set.size();
		int mx = Integer.MAX_VALUE;
		int l = -1;
		int r = -1;
		int[] ans = {0,0};
		HashMap<String,Integer> map = new HashMap<>();
		int cnt = 0;
		while(true) {
			if(cnt==msz) {
				l++;
				if(map.get(gems[l])==1) {
					map.remove(gems[l]);
					cnt--;
				}else {
					map.put(gems[l], map.get(gems[l])-1);
					if(r-l<mx) {
						mx = r-l;
						ans[0] = l+2;
						ans[1] = r+1;
					}
				}
			}else {
				r++;
				if(r==sz) break;
				if(!map.containsKey(gems[r])) {
					map.put(gems[r], 1);
					cnt++;
					if(cnt==msz) {
						if(r-l<mx) {
							mx = r-l;
							ans[0] = l+2;
							ans[1] = r+1;
						}
					}
				}else {
					map.put(gems[r], map.get(gems[r])+1);
				}
			}
		}
        return ans;
    }
}
