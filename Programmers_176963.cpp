#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> mapScore;
    int iSize = name.size();
    for(int i=0;i<iSize;++i)
    {
        mapScore.insert({name[i],yearning[i]});
    }
    for(vector<string> vecString : photo)
    {
        int iScore = 0;
        for(string str : vecString)
        {
            if(mapScore.find(str)!=mapScore.end())
            {
                iScore += mapScore[str];
            }
        }
        answer.push_back(iScore);
    }
    return answer;
}
