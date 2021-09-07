import java.util.*;

class Solution {
    public int solution(int[][] board, int[] moves){
      int l,c,sz,i,j,t,ans;
      l = board.length;
      c = board[0].length;
      Stack<Integer> stack = new Stack<>(); 
      sz = moves.length;
      ans = 0;
      for(i=0;i<sz;i++) {
        t = moves[i]-1;
        for(j=0;j<l;j++) {
          if(board[j][t]!=0) {
            if(stack.isEmpty()) {
              stack.add(board[j][t]);
            }else {
              if(stack.peek()==board[j][t]) {
                stack.pop();
                ans += 2;
              }else {
                stack.add(board[j][t]);
              }
            }
            board[j][t] = 0;
            break;
          }
        }
      }
      return ans;
    }
}
