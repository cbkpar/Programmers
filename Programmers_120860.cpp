#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    int idX = 0;
    int idY = 0;
    for(int i=1;i<4;++i)
    {
        if(dots[0][0] != dots[i][0])
        {
            idX = dots[0][0]-dots[i][0];
            if(idX < 0) idX = -idX;
            break;
        }
    }
    for(int i=1;i<4;++i)
    {
        if(dots[0][1] != dots[i][1])
        {
            idY = dots[0][1]-dots[i][1];
            if(idY < 0) idY = -idY;
            break;
        }
    }
    answer = idX * idY;
    return answer;
}
