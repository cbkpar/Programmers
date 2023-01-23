#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    int arrCount[200] = {0,};
    for(vector<int> arrLine : lines)
    {
        int iStart = arrLine[0] + 100;
        int iEnd = arrLine[1] + 100;
        for(int i=iStart;i<iEnd;++i)
        {
            ++arrCount[i];
        }
    }
    for(int i=0;i<200;++i)
    {
        if(arrCount[i] >= 2)
        {
            ++answer;
        }
    }
    return answer;
}
