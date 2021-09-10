import java.util.*;

class Solution {
    public String solution(int n) {
        StringBuilder sb = new StringBuilder();
        Stack<Integer> stack = new Stack<>(); 
        while(true) {
        	int t = (n-1)%3+1;
        	if(t==1) stack.add(1);
        	if(t==2) stack.add(2);
        	if(t==3) stack.add(4);
        	n -= t;
        	n /= 3;
        	if(n==0) break;
        }
        while(!stack.isEmpty()) sb.append(stack.pop());
        return sb.toString();
    }
}
