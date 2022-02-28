import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int sz = prices.length;
        int[] ans = new int[sz];
        Stack<stock> stack = new Stack<>();
        stack.add(new stock(prices[0], 0));
        for (int i = 1; i < sz; i++) {
            while (!stack.isEmpty()) {
                if (stack.peek().num <= prices[i]) break;
                ans[stack.peek().pos] = i - stack.peek().pos;
                stack.pop();
            }
            stack.add(new stock(prices[i], i));
        }
        while (!stack.isEmpty()) {
            ans[stack.peek().pos] = sz - stack.peek().pos - 1;
            stack.pop();
        }
        return ans;
    }
}

class stock {
    int num;
    int pos;

    public stock(int num, int pos) {
        this.num = num;
        this.pos = pos;
    }
}
