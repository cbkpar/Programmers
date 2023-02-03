#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int iR1 = arr1.size();
    int iC1 = arr1[0].size();
    int iR2 = arr2.size();
    int iC2 = arr2[0].size();
    for(int i=0;i<iR1;++i)
    {
        vector<int> vecTemp;
        for(int j=0;j<iC2;++j)
        {
            int iTemp = 0;
            for(int k=0;k<iC1;++k)
            {
                iTemp += arr1[i][k] * arr2[k][j];
            }
            vecTemp.push_back(iTemp);
        }
        answer.push_back(vecTemp);
    }
    return answer;
}
