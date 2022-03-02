import java.util.*;

class Solution {
    public int solution(String name) {
        return solve(name);
    }
    
    private static int solve(String str) {
        int sz = str.length();
        ArrayList<Integer> arr = new ArrayList<>();
        int cnt = 0;
        for (int i = 0; i < sz; i++) {
            if (str.charAt(i) == 'A') continue;
            cnt += Math.min(str.charAt(i) - 'A', 'Z' - str.charAt(i) + 1);
            arr.add(i);
        }
        int asz = arr.size();
        if (asz == 1) {
            cnt += Math.min(arr.get(0), sz - arr.get(0));
        } else if (asz > 1) {
            int m_cnt = Math.min(arr.get(asz - 1), sz - arr.get(0));
            for (int i = 0; i < asz - 1; i++) {
                int left = arr.get(i);
                int right = sz - arr.get(i + 1);
                m_cnt = Math.min(m_cnt, Math.min(left * 2 + right, left + right * 2));
            }
            cnt += m_cnt;
        }
        return cnt;
    }
}
