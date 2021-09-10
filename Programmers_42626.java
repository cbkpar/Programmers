import java.util.*;

class Solution {
    public int solution(int[] scoville, int k) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for(int t:scoville) q.add(t);
        int cnt = 0;
        while(q.size()>1) {
            if(q.peek()>=k) break;
            int t = q.poll();
            t += q.poll()*2;
            q.add(t);
            cnt++;
        }
        if(q.peek()>=k) {
            return cnt;
        }else {
            return -1;
        }
    }
}
