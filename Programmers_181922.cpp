#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(const vector<int>& vecQuery : queries)
    {
        int iS = vecQuery[0];
        int iE = vecQuery[1];
        int iK = vecQuery[2];
        for(int i=iS;i<=iE;++i)
        {
            if(i%iK==0)
            {
                ++arr[i];
            }
        }
    }
    return arr;
}
