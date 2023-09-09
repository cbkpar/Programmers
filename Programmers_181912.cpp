#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    for(const string& strNum : intStrs)
    {
        int iTemp = 0;
        for(int i=s;i<s+l;++i)
        {
            iTemp *= 10;
            iTemp += strNum[i] - '0';
        }
        if(iTemp > k)
        {
            answer.push_back(iTemp);
        }
    }
    return answer;
}
