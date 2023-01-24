#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    istringstream ss(s);
    string strTemp;
    int iBefore = 0;
    while(getline(ss, strTemp, ' '))
    {
        if(strTemp == "Z")
        {
            answer -= iBefore;
        }
        else
        {
            int iNumber = stoi(strTemp);
            iBefore = iNumber;
            answer += iNumber;
        }
    }
    
    return answer;
}
