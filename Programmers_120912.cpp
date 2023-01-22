#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for(int iNum : array)
    {
        while(iNum > 0)
        {
            if(iNum%10 == 7) ++ answer;
            iNum /= 10;
        }
    }
    return answer;
}
