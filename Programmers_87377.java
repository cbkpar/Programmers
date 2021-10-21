import java.util.*;

class Solution {
    public String[] solution(int[][] line) {
        long ymax = Long.MIN_VALUE;
        long ymin = Long.MAX_VALUE;
        long xmax = Long.MIN_VALUE;
        long xmin = Long.MAX_VALUE;
        ArrayList<pos> arr = new ArrayList<>();
        int sz = line.length;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (i == j) continue;
                long C = line[i][0] * line[j][1] - line[i][1] * line[j][0];
                if (C == 0) continue;
                long A = (long) line[i][1] * line[j][2] - (long) line[i][2] * line[j][1];
                long B = (long) line[i][2] * line[j][0] - (long) line[i][0] * line[j][2];
                if (A % C != 0) continue;
                if (B % C != 0) continue;
                long x = A / C;
                long y = B / C;
                arr.add(new pos(y, x));
                ymin = Math.min(ymin, y);
                ymax = Math.max(ymax, y);
                xmin = Math.min(xmin, x);
                xmax = Math.max(xmax, x);
            }
        }
        int[][] map = new int[(int) (ymax - ymin + 1)][(int) (xmax - xmin + 1)];
        for (pos p : arr) map[(int) (p.y - ymin)][(int) (p.x - xmin)] = 1;
        String[] ans = new String[(int) (ymax - ymin + 1)];
        int ysz = (int) (ymax - ymin);
        for (int i = (int) (ymax - ymin); i >= 0; i--) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < (int) (xmax - xmin + 1); j++) {
                if (map[i][j] == 1) {
                    sb.append("*");
                } else {
                    sb.append(".");
                }
            }
            ans[ysz-i] = sb.toString();
        }
        return ans;
    }
}

class pos {
    long y, x;

    public pos(long y, long x) {
        this.y = y;
        this.x = x;
    }
}
