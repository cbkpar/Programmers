#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    int iSize = num_list.size();
    for(int i=0;i<iSize;i+=n)
    {
        vector<int> vecTemp;
        for(int j=0;j<n;++j)
        {
            vecTemp.push_back(num_list[i+j]);
        }
        answer.push_back(vecTemp);
    }
    return answer;
}
