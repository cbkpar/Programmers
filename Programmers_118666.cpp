#include <string>
#include <vector>

using namespace std;

string arrType[8] = {"RT", "TR", "CF", "FC", "JM", "MJ", "AN", "NA"};

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int iScore[4] = {0,};
    int iSize = survey.size();
    for(int i=0;i<iSize;++i)
    {
        for(int j=0;j<8;++j)
        {
            if(survey[i] == arrType[j])
            {
                iScore[j/2] += (choices[i]-4) * (j%2==0?-1:1);
            }
        }
    }
    answer += (iScore[0]>=0?"R":"T");
    answer += (iScore[1]>=0?"C":"F");
    answer += (iScore[2]>=0?"J":"M");
    answer += (iScore[3]>=0?"A":"N");
    return answer;
}
