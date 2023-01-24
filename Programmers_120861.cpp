#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    int iX = 0;
    int iY = 0;
    int iSizeX = board[0] / 2;
    int iSizeY = board[1] / 2;
    for(string strCommand : keyinput)
    {
        if(strCommand == "left")
        {
            if(iX > iSizeX * -1) --iX;
        }
        if(strCommand == "right")
        {
            if(iX < iSizeX) ++iX;
        }
        if(strCommand == "up")
        {
            if(iY < iSizeY) ++iY;
        }
        if(strCommand == "down")
        {
            if(iY > iSizeY * -1) --iY;
        }
    }
    answer.push_back(iX);
    answer.push_back(iY);
    return answer;
}
