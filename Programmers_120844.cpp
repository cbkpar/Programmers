#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    int iSize = numbers.size();
    int iOffset = (direction=="right"?iSize-1:1);
    for(int i=0;i<iSize;++i)
    {
        answer.push_back(numbers[(i+iOffset)%iSize]);
    }
    return answer;
}
