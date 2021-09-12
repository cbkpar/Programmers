import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
		int sz,i,cnt;
		sz = priorities.length;
		Queue<paper> q = new LinkedList<>();
		PriorityQueue<Integer> p = new PriorityQueue<>(Collections.reverseOrder());
		for(i=0;i<sz;i++) {
			q.add(new paper(i,priorities[i]));
			p.add(priorities[i]);
		}
		cnt = 1;
		while(true) {
			if(q.peek().prior==p.peek()) {
				if(q.peek().num==location) {
					return cnt;
				}else {
					q.poll();
					p.poll();
					cnt++;
				}
			}else {
				q.add(q.poll());
			}
		}
    }
}

class paper {
	int num, prior;
	public paper(int num, int prior) {
		this.num = num;
		this.prior = prior;
	}
}
