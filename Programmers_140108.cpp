#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int iCount = 0;
    char ch;
    
    int iSize = s.length();
    for(int i=0;i<iSize;++i)
    {
        if(iCount == 0)
        {
            ++answer;
            iCount = 1;
            ch = s[i];
        }
        else
        {
            if(s[i]==ch)
            {
                ++iCount;
            }
            else
            {
                --iCount;
            }
        }
    }
    return answer;
}
