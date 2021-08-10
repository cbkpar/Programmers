import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int solution(int[][] board) {
        int n = board.length;
        boolean[][][] visited = new boolean[n][n][2];
        Queue<robot> q = new LinkedList<>();
        q.add(new robot(0,0,0));
        visited[0][0][0] = true;
        int t = 0;
        while(true){
            if(visited[n-1][n-2][0]||visited[n-2][n-1][1]){
                return t;
            }
            if(q.isEmpty()) break;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                robot p = q.poll();
                if(p.d==0){
                    if(p.x-1>=0) if(!visited[p.y][p.x-1][0]&&board[p.y][p.x-1]==0){
                        visited[p.y][p.x-1][0] = true;
                        q.add(new robot(p.y,p.x-1,0));
                    }
                    if(p.x+1<n-1) if(!visited[p.y][p.x+1][0]&&board[p.y][p.x+2]==0){
                        visited[p.y][p.x+1][0] = true;
                        q.add(new robot(p.y,p.x+1,0));
                    }
                    if(p.y-1>=0) if(board[p.y-1][p.x]==0&&board[p.y-1][p.x+1]==0){
                        if(!visited[p.y-1][p.x][1]){
                            visited[p.y-1][p.x][1] = true;
                            q.add(new robot(p.y-1,p.x,1));
                        }
                        if(!visited[p.y-1][p.x+1][1]){
                            visited[p.y-1][p.x+1][1] = true;
                            q.add(new robot(p.y-1,p.x+1,1));
                        }
                        if(!visited[p.y-1][p.x][0]){
                            visited[p.y-1][p.x][0] = true;
                            q.add(new robot(p.y-1,p.x,0));
                        }
                    }
                    if(p.y+1<n) if(board[p.y+1][p.x]==0&&board[p.y+1][p.x+1]==0){
                        if(!visited[p.y][p.x][1]){
                            visited[p.y][p.x][1] = true;
                            q.add(new robot(p.y,p.x,1));
                        }
                        if(!visited[p.y][p.x+1][1]){
                            visited[p.y][p.x+1][1] = true;
                            q.add(new robot(p.y,p.x+1,1));
                        }
                        if(!visited[p.y+1][p.x][0]){
                            visited[p.y+1][p.x][0] = true;
                            q.add(new robot(p.y+1,p.x,0));
                        }
                    }
                }else{
                    if(p.y-1>=0) if(!visited[p.y-1][p.x][1]&&board[p.y-1][p.x]==0){
                        visited[p.y-1][p.x][1] = true;
                        q.add(new robot(p.y-1,p.x,1));
                    }
                    if(p.y+1<n-1) if(!visited[p.y+1][p.x][1]&&board[p.y+2][p.x]==0){
                        visited[p.y+1][p.x][1] = true;
                        q.add(new robot(p.y+1,p.x,1));
                    }
                    if(p.x-1>=0) if(board[p.y][p.x-1]==0&&board[p.y+1][p.x-1]==0){
                        if(!visited[p.y][p.x-1][0]){
                            visited[p.y][p.x-1][0] = true;
                            q.add(new robot(p.y,p.x-1,0));
                        }
                        if(!visited[p.y+1][p.x-1][0]){
                            visited[p.y+1][p.x-1][0] = true;
                            q.add(new robot(p.y+1,p.x-1,0));
                        }
                        if(!visited[p.y][p.x-1][1]){
                            visited[p.y][p.x-1][1] = true;
                            q.add(new robot(p.y,p.x-1,1));
                        }
                    }
                    if(p.x+1<n) if(board[p.y][p.x+1]==0&&board[p.y+1][p.x+1]==0){
                        if(!visited[p.y][p.x][0]){
                            visited[p.y][p.x][0] = true;
                            q.add(new robot(p.y,p.x,0));
                        }
                        if(!visited[p.y+1][p.x][0]){
                            visited[p.y+1][p.x][0] = true;
                            q.add(new robot(p.y+1,p.x,0));
                        }
                        if(!visited[p.y][p.x+1][1]){
                            visited[p.y][p.x+1][1] = true;
                            q.add(new robot(p.y,p.x+1,1));
                        }
                    }
                } 
            }
            t++;
        }
        return 0;
    }
    
    public static class robot {
		int y;
		int x;
		int d;
		
		public robot(int y, int x, int d) {
			this.y = y;
			this.x = x;
			this.d = d;
		}
	}
}
