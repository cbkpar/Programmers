#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int iMin = 0;
    int iMax = 0;
    for(vector<int> vecSize : sizes)
    {
        int iTempMin = vecSize[0]<vecSize[1]?vecSize[0]:vecSize[1];
        int iTempMax = vecSize[0]>vecSize[1]?vecSize[0]:vecSize[1];
        if(iTempMin > iMin) iMin = iTempMin;
        if(iTempMax > iMax) iMax = iTempMax;
    }
    answer = iMin * iMax;
    return answer;
}
