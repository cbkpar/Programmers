#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    int iCount[10] = {0,};
    for(char ch : my_string)
    {
        if(ch >= '0' && ch <= '9')
        {
            ++iCount[ch-'0'];
        }
    }
    for(int i=0;i<=9;++i)
    {
        while(iCount[i]--)
        {
            answer.push_back(i);
        }
    }
    return answer;
}
