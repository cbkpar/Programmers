#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    for(int iNum : numlist)
    {
        if(iNum%n == 0)
        {
            answer.push_back(iNum);
        }
    }
    return answer;
}
