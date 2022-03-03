import java.util.*;

class Solution {
    public String solution(String number, int k) {
        StringBuilder sb = new StringBuilder();
        int sz = number.length();
        boolean[] chk = new boolean[sz];
        Stack<numbers> stack = new Stack<>();
        for (int i = 0; i < sz; i++) {
            int num = number.charAt(i) - '0';
            while (!stack.isEmpty()) {
                if (k == 0) break;
                if (stack.peek().n >= num) break;
                k--;
                chk[stack.pop().idx] = true;
            }
            stack.add(new numbers(num, i));
        }
        while (k-- > 0) chk[stack.pop().idx] = true;
        for (int i = 0; i < sz; i++) if (!chk[i]) sb.append(number.charAt(i));
        return sb.toString();
    }
}

class numbers {
    int n;
    int idx;

    public numbers(int n, int idx) {
        this.n = n;
        this.idx = idx;
    }
}
