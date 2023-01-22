#include <string>
#include <vector>

using namespace std;

string strNum[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

long long solution(string numbers) {
    long long answer = 0;
    int iSize = numbers.length();
    for(int i=0;i<iSize;)
    {
        answer *= 10;
        for(int j=0;j<10;++j)
        {
            int iLen = strNum[j].length();
            bool bCorrect = false;
            if(i+iLen<=iSize)
            {
                for(int k=0;k<iLen;++k)
                {
                    if(numbers[i+k] != strNum[j][k]) break;
                    if(k==iLen-1) bCorrect = true;
                }
            }
            if(bCorrect)
            {
                answer += j;
                i += iLen;
                break;
            }
        }
    }
    return answer;
}
