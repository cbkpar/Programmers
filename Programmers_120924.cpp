#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int iSize = common.size();
    if(common[0] + common[2] == common[1] * 2)
    {
        answer = common[0] + (common[1] - common[0]) * iSize;
    }
    else
    {
        answer = common[iSize-1] * (common[1] / common[0]);
    }
    return answer;
}
