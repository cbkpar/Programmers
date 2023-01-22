#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    int iSize = cipher.length();
    for(int i=0;i<iSize;++i)
    {
        if((i+1)%code == 0)
        {
            answer += cipher[i];
        }
    }
    return answer;
}
