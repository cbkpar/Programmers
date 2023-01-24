#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int iSize = food.size();
    int iCount = 0;
    for(int i=1;i<iSize;++i)
    {
        food[i] /= 2;
        iCount += food[i];
    }
    answer.resize(iCount*2+1);
    int iIndex = 0;
    for(int i=1;i<iSize;++i)
    {
        for(int j=0;j<food[i];++j)
        {
            answer[iIndex++] = (char)(i+'0');
        }
    }
    answer[iIndex++] = (char)('0');
    for(int i=iSize-1;i>=1;--i)
    {
        for(int j=0;j<food[i];++j)
        {
            answer[iIndex++] = (char)(i+'0');
        }
    }
    return answer;
}
