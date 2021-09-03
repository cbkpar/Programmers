import java.util.*;
import java.io.*;

class Solution {
    public int solution(String s) {
        int sz = s.length();
        int ans = 0;
        int i,j;
        for(i=0;i<sz;i++) {
            String str = s.substring(i)+s.substring(0, i);
            Stack<Character> stack = new Stack<>(); 
            for(j=0;j<sz;j++) {
                if(str.charAt(j)=='{'||str.charAt(j)=='['||str.charAt(j)=='(') {
                    stack.add(str.charAt(j));
                }else {
                    if(stack.isEmpty()) {
                        break;
                    }else {
                        if(str.charAt(j)=='}') {
                            if(stack.peek()=='{') {
                                stack.pop();
                            }else {
                                break;
                            }
                        }else if(str.charAt(j)==']') {
                            if(stack.peek()=='[') {
                                stack.pop();
                            }else {
                                break;
                            }
                        }else {
                            if(stack.peek()=='(') {
                                stack.pop();
                            }else {
                                break;
                            }
                        }
                    }
                }
            }
        if(j==sz&&stack.isEmpty()) ans++;
        }
        return ans;
    }
}
