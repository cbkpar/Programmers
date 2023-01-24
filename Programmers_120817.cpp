#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    for(int iNum : numbers)
    {
        answer += iNum;
    }
    answer /= numbers.size();
    return answer;
}
