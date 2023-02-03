#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1;i<=10000;++i)
    {
        int iNum = i*(i-1)/2;
        if(iNum >= n) break;
        if((n-iNum)%i==0) ++answer;
    }
    return answer;
}
