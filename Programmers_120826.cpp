#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    for(char ch : my_string)
    {
        if(ch == letter[0])
        {
            continue;
        }
        answer += ch;
    }
    return answer;
}
