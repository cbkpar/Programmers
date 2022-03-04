class Solution {
    public long solution(int n, int[] times) {
        long ans = Long.MAX_VALUE;
        int sz = times.length;
        long left = 0;
        long right = 1000000000000000000L;
        while (left <= right) {
            long mid = (left + right) / 2;
            long cnt = 0;
            for (int i = 0; i < sz; i++) cnt += mid / times[i];
            if (cnt >= n) {
                ans = Math.min(ans, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
}
