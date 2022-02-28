import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int n_time = 0;
        int n_weight = 0;
        Queue<truck> q = new LinkedList<>();
        int nowtruck = 0;
        while (true) {
            if (!q.isEmpty()) {
                if (q.peek().t <= n_time) {
                    n_weight -= q.peek().w;
                    q.poll();
                }
            }
            if (n_weight + truck_weights[nowtruck] <= weight) {
                q.add(new truck(n_time + bridge_length, truck_weights[nowtruck]));
                n_time++;
                n_weight += truck_weights[nowtruck++];
                if (nowtruck == truck_weights.length) {
                    return n_time + bridge_length;
                }
            } else {
                n_time = q.peek().t;
            }
        }
    }
}

class truck {
    int t;
    int w;

    public truck(int t, int w) {
        this.t = t;
        this.w = w;
    }
}
