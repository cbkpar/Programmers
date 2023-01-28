#include <string>
#include <vector>

using namespace std;

long long matCount[1001] = {0,};

long long solution(vector<int> weights) {
    long long answer = 0;
    for(int iWeight : weights)
    {
        ++matCount[iWeight];
    }
    for(int i=100;i<=1000;++i)
    {
        answer += matCount[i] * (matCount[i]-1) / 2;
        if(i%2==0&&(i/2)*3<=1000) answer += matCount[i] * matCount[(i/2)*3];
        if(i*2<=1000) answer += matCount[i] * matCount[i*2];
        if(i%3==0&&(i/3)*4<=1000) answer += matCount[i] * matCount[(i/3)*4];
    }
    return answer;
}
