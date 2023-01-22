#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    int iSize = my_str.length();
    for(int i=0;i<iSize;i+=n)
    {
        string str = "";
        for(int j=0;j<n;++j)
        {
            if(i+j<iSize)
            {
                str += my_str[i+j];            
            }
        }
        answer.push_back(str);
    }
    return answer;
}
