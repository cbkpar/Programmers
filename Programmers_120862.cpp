#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1000000000;
    int iSize = numbers.size();
    for(int i=0;i<iSize;++i)
    {
        for(int j=i+1;j<iSize;++j)
        {
            int iTemp = numbers[i] * numbers[j];
            if(iTemp > answer)
            {
                answer = iTemp;
            }
        }
    }
    return answer;
}
