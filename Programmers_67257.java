import java.util.*;

class Solution {
    
    static boolean[] chk = new boolean[3];
    static int[] order = new int[3];
    static int[] oper = {43, 45, 42};
    static long ans = 0;
    static ArrayList<Long> arr;
    
    public long solution(String expression) {
        StringTokenizer digit = new StringTokenizer(expression.replaceAll("[^0-9]", " "));
        StringTokenizer op = new StringTokenizer(expression.replaceAll("[0-9]", " "));
        int sz = digit.countTokens() * 2 - 1;
        arr = new ArrayList<>();
        arr.add((long) Integer.parseInt(digit.nextToken()));
        for (int i = 1; i < sz; i += 2) {
            arr.add((long) op.nextToken().charAt(0));
            arr.add((long) Integer.parseInt(digit.nextToken()));
        }
        dfs(0);
        return ans;
    }
    
    private static void dfs(int k) {
        if (k == 3) {
            ArrayList<Long> tmp = new ArrayList<>();
            for (long t : arr) tmp.add(t);
            for (int i = 0; i < 3; i++) {
                for (int j = 1; j < tmp.size(); j += 2) {
                    if (tmp.get(j) == oper[order[i]]) {
                        if (oper[order[i]] == 43) {
                            tmp.set(j - 1, tmp.get(j - 1) + tmp.get(j + 1));
                            tmp.remove(j);
                            tmp.remove(j);
                        } else if (oper[order[i]] == 45) {
                            tmp.set(j - 1, tmp.get(j - 1) - tmp.get(j + 1));
                            tmp.remove(j);
                            tmp.remove(j);
                        } else {
                            tmp.set(j - 1, tmp.get(j - 1) * tmp.get(j + 1));
                            tmp.remove(j);
                            tmp.remove(j);
                        }
                        j -= 2;
                    }
                }
            }
            ans = Math.max(ans, Math.abs(tmp.get(0)));
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (!chk[i]) {
                chk[i] = true;
                order[k] = i;
                dfs(k + 1);
                chk[i] = false;
            }
        }
    }
}
