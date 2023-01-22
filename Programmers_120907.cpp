#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for(string q : quiz)
    {
        int iLength = q.length();
        int arrNum[3] = {0,};
        bool arrPlus[3] = {true, true, true};
        bool bPlus = true;
        int iState = 0;
        for(int i=0;i<iLength;++i)
        {
            if(iState == 1 && q[i] == '-')
            {
                bPlus = false;
            }
            else if(q[i] >= '0'&& q[i] <= '9')
            {
                arrNum[iState/2] *= 10;
                arrNum[iState/2] += q[i] - '0';
            }
            else if(q[i] == ' ')
            {
                ++iState;
            }
            else if(q[i] == '-')
            {
                arrPlus[iState/2] = false;
            }
        }
        for(int i=0;i<3;++i)
        {
            if(arrPlus[i] == false)
            {
                arrNum[i] *= -1;
            }
        }
        if(arrNum[0] + (bPlus?arrNum[1]:-arrNum[1]) == arrNum[2])
        {
            answer.push_back("O");
        }
        else
        {
            answer.push_back("X");
        }
    }
    return answer;
}
