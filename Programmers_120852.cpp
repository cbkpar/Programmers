#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int iTemp = n;
    for(int i=2;i<=n;++i)
    {
        if(iTemp%i==0)
        {
            answer.push_back(i);
            while(iTemp%i==0)
            {
                iTemp /= i;
            }
        }
    }
    return answer;
}
