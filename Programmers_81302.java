import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int[] solution(String[][] places) {
        int[] answer = new int[5];
        int[] dy = {1,0,-1,0};
        int[] dx = {0,1,0,-1};
        for(int t=0;t<5;t++){
            int[][] map = new int[5][5];
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(places[t][i].charAt(j)=='P') map[i][j] = 1;
                    if(places[t][i].charAt(j)=='X') map[i][j] = 2;
                }
            }
            boolean chk = true;
            boolean[][] visited = new boolean[5][5];
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(map[i][j]==1){
                        Queue<people> q = new LinkedList<>();
                        q.add(new people(i,j));
                        visited[i][j] = true;
                        int cnt = 0;
                        while(!q.isEmpty()){
                            if(cnt++==2||!chk) break;
                            for(int sz=q.size();sz>0;sz--){
                                people p = q.poll();
                                for(int k=0;k<4;k++){
                                    int ny = p.y + dy[k];
                                    int nx = p.x + dx[k];
                                    if(ny<0||ny>4||nx<0||nx>4||visited[ny][nx]) continue;
                                    visited[ny][nx] = true;
                                    if(map[ny][nx]==1){
                                        chk = false;
                                        break;
                                    }
                                    if(map[ny][nx]==0){
                                        q.add(new people(ny,nx));
                                    }
                                }
                            }

                        }
                    }
                }
            }
            if(chk) answer[t] = 1;
        }
        return answer;
    }
    public static class people {
		int y;
		int x;

		public people(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}
}
