#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(char ch : my_string)
    {
        answer = ch + answer;
    }
    return answer;
}
