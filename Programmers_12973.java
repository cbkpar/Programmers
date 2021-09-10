import java.util.*;

class Solution
{
    public int solution(String s) {
		int sz = s.length();
		int i;
		Stack<Character> stack = new Stack<>(); 
		for(i=0;i<sz;i++) {
			if(stack.isEmpty()) {
				stack.add(s.charAt(i));
			}else {
				if(stack.peek()==s.charAt(i)) {
					stack.pop();
				}else {
					stack.add(s.charAt(i));
				}
			}
		}
		return stack.isEmpty()?1:0;
    }
}
