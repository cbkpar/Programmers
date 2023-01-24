#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int iNum : numbers)
    {
        answer.push_back(iNum*2);
    }
    return answer;
}
