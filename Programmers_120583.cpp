#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    for(int iNum : array)
    {
        if(iNum == n)
        {
            ++answer;
        }
    }
    return answer;
}
