#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    for(string strA : s1)
    {
        for(string strB : s2)
        {
            if(strA == strB)
            {
                ++answer;
            }
        }
    }
    return answer;
}
