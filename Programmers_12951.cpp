#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int iSize = s.length();
    answer.resize(iSize);
    bool bUpper = true;
    for(int i=0;i<iSize;++i)
    {
        if(s[i]==' ')
        {
            bUpper = true;
            answer[i] = ' ';
        }
        else
        {
            if(bUpper)
            {
                if(s[i] >= 'a' && s[i] <= 'z')
                {
                    answer[i] = (char)(s[i]-'a'+'A');                    
                }
                else
                {
                    answer[i] = s[i];
                }
            }
            else
            {
                if(s[i] >= 'A' && s[i] <= 'Z')
                {
                    answer[i] = (char)(s[i]-'A'+'a');
                }
                else
                {
                    answer[i] = s[i];
                }
            }
            bUpper = false;
        }
    }
    return answer;
}
