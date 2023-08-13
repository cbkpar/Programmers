#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    int iSize = num_list.size();
    for(int i=0;i<iSize;++i)
    {
        answer.push_back(num_list[i]);
    }
    if(num_list[iSize-1]>num_list[iSize-2])
    {
        answer.push_back(num_list[iSize-1]-num_list[iSize-2]);
    }
    else
    {
        answer.push_back(num_list[iSize-1]*2);
    }
    return answer;
}
