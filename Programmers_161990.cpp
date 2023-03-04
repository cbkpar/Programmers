#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4,0);
    answer[0] = answer[1] = 1000000000;
    int iSize = wallpaper.size();
    for(int i=0;i<iSize;++i)
    {
        int iLen = wallpaper[i].length();
        for(int j=0;j<iLen;++j)
        {
            if(wallpaper[i][j]=='#')
            {
                answer[0] = min(answer[0], i);
                answer[1] = min(answer[1], j);
                answer[2] = max(answer[2], i+1);
                answer[3] = max(answer[3], j+1); 
            }
        }
    }
    return answer;
}
