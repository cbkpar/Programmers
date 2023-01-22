#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(char ch : my_string)
    {
        if(ch >= 'a' && ch <= 'z')
        {
            answer += (char)(ch-'a'+'A');
        }
        else
        {
            answer += (char)(ch-'A'+'a');
        }
    }
    return answer;
}
