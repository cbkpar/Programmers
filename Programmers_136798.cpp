#include <string>
#include <vector>

using namespace std;

int arrCount[100001] = {0,};

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i=1;i<=number;++i)
    {
        for(int j=i;j<=number;j+=i)
        {
            ++arrCount[j];
        }
    }
    for(int i=1;i<=number;++i)
    {
        if(arrCount[i]>limit)
        {
            answer += power;
        }
        else
        {
            answer += arrCount[i];
        }
    }
    return answer;
}
