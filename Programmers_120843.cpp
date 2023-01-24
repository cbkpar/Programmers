#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int iSize = numbers.size();
    int answer = numbers[((k-1)*2)%iSize];
    return answer;
}
