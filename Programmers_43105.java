class Solution {
    public int solution(int[][] triangle) {
        int sz = triangle.length;
        for (int i = 1; i < sz; i++) {
            for (int j = 0; j <= i; j++) {
                int mx = 0;
                if (j != 0) mx = Math.max(mx, triangle[i - 1][j - 1]);
                if (j != i) mx = Math.max(mx, triangle[i - 1][j]);
                triangle[i][j] += mx;
            }
        }
        int mx = 0;
        for (int i = 0; i < sz; i++) mx = Math.max(mx, triangle[sz - 1][i]);
        return mx;
    }
}
