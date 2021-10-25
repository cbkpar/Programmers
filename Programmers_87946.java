import java.util.*;

class Solution {

    static int n, ans;
    static boolean[] chk;
    static int[][] arr;
    
    public int solution(int k, int[][] dungeons) {
        arr = dungeons.clone();
        n = dungeons.length;
        chk = new boolean[n];
        ans = 0;
        btr(0, k);
        return ans;
    }
    private static void btr(int k, int h) {
        ans = Math.max(ans, k);
        for (int i = 0; i < n; i++) {
            if (!chk[i] && h >= arr[i][0]) {
                chk[i] = true;
                btr(k + 1, h - arr[i][1]);
                chk[i] = false;
            }
        }
    }
}
