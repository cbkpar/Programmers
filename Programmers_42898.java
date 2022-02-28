class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int[][] map = new int[n + 1][m + 1];
        map[1][1] = 1;
        boolean[][] ispuddle = new boolean[n + 1][m + 1];
        int sz = puddles.length;
        for (int i = 0; i < sz; i++) ispuddle[puddles[i][1]][puddles[i][0]] = true;
        ispuddle[1][1] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (ispuddle[i][j]) continue;
                map[i][j] = (map[i - 1][j] + map[i][j - 1]) % 1000000007;
            }
        }
        return map[n][m];
    }
}
