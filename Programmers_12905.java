class Solution
{
    public int solution(int [][]board)
    {
        int i,j,m;
        int r = board.length;
        int c = board[0].length;
        for(i=1;i<r;i++){
            for(j=1;j<c;j++){
                if(board[i][j]==1){
                    board[i][j] = Math.min(board[i-1][j-1],Math.min(board[i-1][j],board[i][j-1])) + 1;
                }
            }
        }
        m = 0;
        for(i=0;i<r;i++) for(j=0;j<c;j++) m = Math.max(m, board[i][j]);
        return m*m;
    }
}
