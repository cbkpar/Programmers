import java.util.*;

class Solution {
    
    static ArrayList<Integer>[] arr = new ArrayList[108];
    static int score;
    
    public int[] solution(String[] info, String[] query) {
        for (int i = 0; i < 108; i++) arr[i] = new ArrayList<>();
        int n = info.length;
        int m = query.length;
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(info[i]);
            String str = st.nextToken();
            int a = 0;
            int b = 0;
            int c = 0;
            int d = 0;
            if (str.equals("java")) a = 1;
            if (str.equals("python")) a = 2;
            str = st.nextToken();
            if (str.equals("frontend")) b = 1;
            str = st.nextToken();
            if (str.equals("senior")) c = 1;
            str = st.nextToken();
            if (str.equals("pizza")) d = 1;
            score = Integer.parseInt(st.nextToken());
            makearr1(a, b, c, d, 0);
        }
        for (int i = 0; i < 108; i++) Collections.sort(arr[i]);
        int[] ans = new int[m];
        for (int i = 0; i < m; i++) {
            int q = 0;
            StringTokenizer st = new StringTokenizer(query[i]);
            String str = st.nextToken();
            if (str.equals("java")) q += 1;
            if (str.equals("python")) q += 2;
            if (str.equals("-")) q += 3;
            q *= 3;
            st.nextToken();
            str = st.nextToken();
            if (str.equals("frontend")) q += 1;
            if (str.equals("-")) q += 2;
            q *= 3;
            st.nextToken();
            str = st.nextToken();
            if (str.equals("senior")) q += 1;
            if (str.equals("-")) q += 2;
            q *= 3;
            st.nextToken();
            str = st.nextToken();
            if (str.equals("pizza")) q += 1;
            if (str.equals("-")) q += 2;
            int s = Integer.parseInt(st.nextToken());
            int left = 0;
            int right = arr[q].size();
            int tmp = 0;
            while (left < right) {
                int mid = (left + right) / 2;
                if (arr[q].get(mid) >= s) {
                    right = mid;
                    tmp = Math.max(tmp, mid);
                } else {
                    left = mid + 1;
                }
            }
            ans[i] = arr[q].size() - right;
        }
        return ans;
    }
    
    private static void makearr1(int a, int b, int c, int d, int s) {
        makearr2(b, c, d, s + a);
        makearr2(b, c, d, s + 3);
    }

    private static void makearr2(int b, int c, int d, int s) {
        makearr3(c, d, (s * 3) + b);
        makearr3(c, d, (s * 3) + 2);
    }

    private static void makearr3(int c, int d, int s) {
        makearr4(d, (s * 3) + c);
        makearr4(d, (s * 3) + 2);
    }

    private static void makearr4(int d, int s) {
        arr[s * 3 + d].add(score);
        arr[s * 3 + 2].add(score);
    }
}
