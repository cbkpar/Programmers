#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    
    int iSize = included.size();
    for(int i=0;i<iSize;++i)
    {
        if(included[i])
        {
            answer += a + d * i;
        }
    }
    return answer;
}
