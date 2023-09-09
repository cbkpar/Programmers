#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for(const vector<int>& vecQuery : queries)
    {
        int iS = vecQuery[0];
        int iE = vecQuery[1];
        int iK = vecQuery[2];
        int iAns = 1000000000;
        for(int i=iS;i<=iE;++i)
        {
            if(arr[i]>iK)
            {
                iAns = min(iAns, arr[i]);
            }
        }
        if(iAns == 1000000000) iAns = -1;
        answer.push_back(iAns);
    }
    return answer;
}
