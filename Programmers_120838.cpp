#include <string>
#include <vector>
#include <sstream>

using namespace std;

string morse[26] = { 
    ".-","-...","-.-.","-..",".","..-.",
    "--.","....","..",".---","-.-",".-..",
    "--","-.","---",".--.","--.-",".-.",
    "...","-","..-","...-",".--","-..-",
    "-.--","--.."
};

string solution(string letter) {
    string answer = "";
    istringstream ss(letter);
    string stringbuffer;
    while(getline(ss, stringbuffer, ' '))
    {
        for(int i=0;i<26;++i)
        {
            if(stringbuffer == morse[i])
            {
                answer += (char)(i+'a');
                break;
            }
        }
    }
    return answer;
}
