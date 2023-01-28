#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long lNumber = left; lNumber <= right; ++lNumber)
    {
        long long lR = lNumber / n + 1;
        long long lC = lNumber % n + 1;
        answer.push_back((int)(lR>lC?lR:lC));
    }
    return answer;
}
