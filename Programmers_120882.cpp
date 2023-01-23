#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    for(vector<int> arrScore : score)
    {
        int iRank = 1;
        for(vector<int> arrScore2 : score)
        {
            if(arrScore[0] + arrScore[1] < arrScore2[0] + arrScore2[1])
            {
                ++iRank;
            }
        }
        answer.push_back(iRank);
    }
    return answer;
}
