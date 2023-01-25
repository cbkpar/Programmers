#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int matCount[1001][1001] = {0,};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> mapIndex;
    int iSize = id_list.size();
    for(int i=0;i<iSize;++i)
    {
        mapIndex[id_list[i]] = i;
    }
    for(string strReport : report)
    {
        istringstream ss(strReport);
        string strNameA, strNameB;
        ss >> strNameA >> strNameB;
        ++matCount[mapIndex[strNameA]][mapIndex[strNameB]];
    }
    answer.resize(iSize);
    for(int i=0;i<iSize;++i)
    {
        int iCount = 0;
        for(int j=0;j<iSize;++j)
        {
            if(matCount[j][i] >= 1)
            {
                ++iCount;
            }
        }
        if(iCount >= k)
        {
            for(int j=0;j<iSize;++j)
            {
                if(matCount[j][i] >= 1)
                {
                    ++answer[j];
                }
            }
        }
    }
    return answer;
}
