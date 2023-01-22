#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    bool bVisited[256] = {false,};
    for(char ch : my_string)
    {
        if(bVisited[ch]) continue;
        bVisited[ch] = true;
        answer += ch;
    }
    return answer;
}
