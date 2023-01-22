#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    
    int iSum = num * (num+1) / 2;
    int iDiff = (iSum - total) / num;
    for(int i=1;i<=num;++i)
    {
        answer.push_back(i-iDiff);
    }
    return answer;
}
