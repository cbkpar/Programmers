import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(int[] weights, String[] head2head) {
		int sz,i,j,win,total,cnt;
		ArrayList<boxer> B = new ArrayList<boxer>();
		sz = weights.length;
		for(i=0;i<sz;i++) {
			win = total = cnt = 0;
			for(j=0;j<sz;j++) {
				if(i==j) continue;
				if(head2head[i].charAt(j)=='W') {
					win++;
                    total++;
					if(weights[j]>weights[i]) cnt++;
				}else if(head2head[i].charAt(j)=='L'){
                    total++;
                }
			}
            if(total==0) total = 1;
			B.add(new boxer((double)win/total,cnt,weights[i],i+1));
		}
		Collections.sort(B, new Comparator<boxer>(){
			@Override
			public int compare(boxer o1, boxer o2) {
				if(o1.win!=o2.win) return (o2.win - o1.win>0?1:-1);
				if(o1.cnt!=o2.cnt) return o2.cnt - o1.cnt;
				if(o1.weight!=o2.weight) return o2.weight - o1.weight;
    			return o1.num - o2.num;
			}
		});
		int[] ans = new int[sz];
		for(i=0;i<sz;i++) ans[i] = B.get(i).num;
		return ans;
    }
}

class boxer {
    double win;
	int cnt, weight, num;
	public boxer(double win, int cnt, int weight, int num) {
		this.win = win;
		this.cnt = cnt;
		this.weight = weight;
		this.num = num;
	}
}
