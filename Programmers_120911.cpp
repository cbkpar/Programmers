#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    int arrCount[26] = {0,};
    for(char ch : my_string)
    {
        if(ch >= 'A' && ch <= 'Z')
        {
            ++arrCount[ch-'A'];
        }
        else
        {
            ++arrCount[ch-'a'];
        }
    }
    for(int i=0;i<26;++i)
    {
        while(arrCount[i]--)
        {
            answer += (char)(i+'a');
        }
    }
    return answer;
}
