#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int arrCount[26] = {0,};
    for(char ch : s)
    {
        ++arrCount[ch-'a'];
    }
    for(int i=0;i<26;++i)
    {
        if(arrCount[i] == 1)
        {
            answer += (char)(i+'a');
        }
    }
    return answer;
}
