#include <string>
#include <vector>

using namespace std;

bool bVisited[1000001] = {false,};

int solution(vector<int> elements) {
    int answer = 0;
    int iSize = elements.size();
    for(int i=0;i<iSize;++i)
    {
        int iSum = 0;
        for(int j=0;j<iSize;++j)
        {
            iSum += elements[(i+j)%iSize];
            if(!bVisited[iSum])
            {
                ++answer;
                bVisited[iSum] = true;
            }
        }
    }
    
    return answer;
}
