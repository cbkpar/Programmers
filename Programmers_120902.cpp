#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    int iTemp = 0;
    bool bPlus = true;
    for(char ch : my_string)
    {
        if(ch >= '0' && ch <= '9')
        {
            iTemp *= 10;
            iTemp += ch - '0';
        }
        else if(ch == '+')
        {
            answer += iTemp * (bPlus?1:-1);
            iTemp = 0;
            bPlus = true;

        }
        else if(ch == '-')
        {
            answer += iTemp * (bPlus?1:-1);
            iTemp = 0;
            bPlus = false;
        }
    }
    answer += iTemp * (bPlus?1:-1);
    return answer;
}
