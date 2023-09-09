#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> index_list) {
    string answer = "";
    int iLen = index_list.size();
    answer.resize(iLen);
    for(int i=0;i<iLen;++i)
    {
        answer[i] = my_string[index_list[i]];
    }
    return answer;
}
