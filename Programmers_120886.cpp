#include <string>
#include <vector>

using namespace std;

int solution(string before, string after) {
    int arrCount[26] = {0,};
    for(char ch : before)
    {
        ++arrCount[ch - 'a'];
    }
    for(char ch : after)
    {
        --arrCount[ch - 'a'];
    }
    for(int i=0;i<26;++i)
    {
        if(arrCount[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}
