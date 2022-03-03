import java.util.*;

class Solution {
    
    static int[] par;
    
    public int solution(int n, int[][] costs) {
        par = new int[n];
        for (int i = 0; i < n; i++) par[i] = i;
        PriorityQueue<node> pq = new PriorityQueue<>();
        int sz = costs.length;
        for (int i = 0; i < sz; i++) pq.add(new node(costs[i][0], costs[i][1], costs[i][2]));

        int cost = 0;
        int link = 0;
        while (!pq.isEmpty()) {
            if (link == n - 1) break;
            node N = pq.poll();
            if (find(N.s) == find(N.e)) continue;
            cost += N.w;
            union(N.s, N.e);
        }
        return cost;
    }
    
    private static int find(int x) {
        if (x == par[x]) return par[x];
        return par[x] = find(par[x]);
    }

    private static void union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        par[y] = x;
    }
}

class node implements Comparable<node> {
    int s;
    int e;
    int w;

    public node(int s, int e, int w) {
        this.s = s;
        this.e = e;
        this.w = w;
    }

    @Override
    public int compareTo(node o) {
        return Integer.compare(this.w, o.w);
    }
}
