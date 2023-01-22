#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    int iMax = -1;
    int iIndex = -1;
    int iSize = array.size();
    for(int i=0;i<iSize;++i)
    {
        if(array[i] > iMax)
        {
            iMax = array[i];
            iIndex = i;
        }
    }
    answer.push_back(iMax);
    answer.push_back(iIndex);
    return answer;
}
