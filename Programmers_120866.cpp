#include <string>
#include <vector>

using namespace std;

int matCount[102][102] = {0,};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int iSize = board.size();
    for(int i=0;i<iSize;++i)
    {
        for(int j=0;j<iSize;++j)
        {
            if(board[i][j] == 1)
            {
                for(int p=-1;p<=1;++p)
                {
                    for(int q=-1;q<=1;++q)
                    {
                        int iNextR = i+p+1;
                        int iNextC = j+q+1;
                        ++matCount[iNextR][iNextC];
                    }
                }
            }
        }
    }
    for(int i=1;i<=iSize;++i)
    {
        for(int j=1;j<=iSize;++j)
        {
            if(matCount[i][j] == 0)
            {
                ++answer;
            }
        }
    }
    return answer;
}
