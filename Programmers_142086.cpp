#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int arrIndex[26] = {0,};
    for(int i=0;i<26;++i) arrIndex[i] = -1;
    int iSize = s.length();
    for(int i=0;i<iSize;++i)
    {
        if(arrIndex[s[i]-'a'] == -1)
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i-arrIndex[s[i]-'a']);
        }
        arrIndex[s[i]-'a'] = i;
    }
    return answer;
}
