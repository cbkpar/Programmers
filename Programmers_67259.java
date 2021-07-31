import java.util.Arrays;

class Solution {
    
    static int[][][] cost;
    static int n;
    static int[] dx = {0,1,0,-1};
    static int[] dy = {1,0,-1,0};
    static boolean[][] chk;
    
    public int solution(int[][] board) {
        n = board.length;
        cost = new int[n][n][2];
        chk = new boolean[n][n];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(board[i][j]==1) chk[i][j] = true;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) Arrays.fill(cost[i][j],Integer.MAX_VALUE);
        dfs(0,0,0,0);
        dfs(0,0,1,0);
        return Math.min(cost[n-1][n-1][0], cost[n-1][n-1][1]);
    }
    
    public static void dfs(int y, int x, int d, int c){
        if(y==n-1&&x==n-1) return;
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0||ny>n-1||nx<0||nx>n-1||chk[ny][nx]) continue;
            int co = c + ((d+i)%2==0?100:600);
            if(i%2==0){
                if(co<cost[ny][nx][0]){
                    cost[ny][nx][0] = co;
                    dfs(ny,nx,i%2,co);
                }
            }else{
                if(co<cost[ny][nx][1]){
                    cost[ny][nx][1] = co;
                    dfs(ny,nx,i%2,co);
                }
            }
        }
        
    }
}
