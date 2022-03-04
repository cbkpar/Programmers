import java.util.*;

class Solution {
    public int solution(int distance, int[] rocks, int n) {
        Arrays.sort(rocks);
        int sz = rocks.length;
        int[] dist = new int[sz + 1];
        dist[0] = rocks[0];
        for (int i = 1; i < sz; i++) dist[i] = rocks[i] - rocks[i - 1];
        dist[sz] = distance - rocks[sz-1];
        int left = 1;
        int right = distance;
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            int sum = 0;
            for (int i = 0; i < sz + 1; i++) {
                sum += dist[i];
                if (sum >= mid) {
                    sum = 0;
                }else{
                    cnt++;
                }
            }
            if (cnt > n) {
                right = mid - 1;
            } else {
                ans = Math.max(ans, mid);
                left = mid + 1;
            }
        }
        return ans;
    }
}
