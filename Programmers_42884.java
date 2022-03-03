import java.util.*;

class Solution {
    public int solution(int[][] routes) {
        Arrays.sort(routes, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] == o2[0]) return o2[1] - o1[1];
                return o1[0] - o2[0];
            }
        });
        int cnt = 0;
        int pos = 0;
        int sz = routes.length;
        while (pos < sz) {
            int mx = routes[pos][1];
            pos++;
            cnt++;
            while (pos < sz) {
                if (routes[pos][0] > mx) break;
                mx = Math.min(mx, routes[pos][1]);
                pos++;
            }
        }
        return cnt;
    }
}
