#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    answer.resize(2);
    for(int iNum : num_list)
    {
        ++answer[iNum%2];
    }
    return answer;
}
