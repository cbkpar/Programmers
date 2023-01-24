#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    int iTemp = 0;
    for(char ch : my_string)
    {
        if(ch >= '0' && ch <= '9')
        {
            iTemp *= 10;
            iTemp += ch - '0';
        }
        else
        {
            answer += iTemp;
            iTemp = 0;
        }
    }
    answer += iTemp;
    return answer;
}
