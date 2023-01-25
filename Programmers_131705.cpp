#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    int iSize = number.size();
    for(int i=0;i<iSize;++i)
    {
        for(int j=i+1;j<iSize;++j)
        {
            for(int k=j+1;k<iSize;++k)
            {
                if(number[i]+number[j]+number[k]==0)
                {
                    ++answer;
                }
            }
        }
    }
    return answer;
}
