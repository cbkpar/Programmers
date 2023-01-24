#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int iLenT = t.length();
    int iLenP = p.length();
    for(int i=0;i<iLenT-iLenP+1;++i)
    {
        if(t.substr(i,iLenP) <= p)
        {
            ++answer;
        }
    }
    return answer;
}
