#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(true)
    {
        bool bChanged = false;
        
        vector<vector<bool>> matDelete(m, vector<bool>(n,false));
        vector<vector<char>> matBoard(m, vector<char>(n,'.'));
        
        for(int i=0;i<m-1;++i)
        {
            for(int j=0;j<n-1;++j)
            {
                if(board[i][j] != '.')
                {
                    if(board[i][j] != board[i][j+1]) continue;
                    if(board[i][j] != board[i+1][j]) continue;
                    if(board[i][j] != board[i+1][j+1]) continue;
                    matDelete[i][j] = matDelete[i][j+1] = matDelete[i+1][j] = matDelete[i+1][j+1] = true;
                    bChanged = true;
                }
            }
        }
        if(!bChanged) break;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matDelete[i][j])
                {
                    ++answer;
                    board[i][j] = '.';
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            int iIndex = m-1;
            for(int j=m-1;j>=0;--j)
            {
                if(board[j][i] != '.')
                {
                    matBoard[iIndex--][i] = board[j][i];
                }
            }
        }
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                board[i][j] = matBoard[i][j];
            }
        }
    }
    return answer;
}
