#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {

    map<string, int> mapPlayer;
    map<int, string> mapPlayer2;
    int iSize = players.size();
    for(int i=0;i<iSize;++i)
    {
        mapPlayer.insert({players[i],i});
        mapPlayer2.insert({i,players[i]});
    }
    for(string strPlayer : callings)
    {
        int iNum = mapPlayer[strPlayer];
        string strPlayer2 = mapPlayer2[iNum-1];
        mapPlayer[strPlayer] = iNum-1;
        mapPlayer[strPlayer2] = iNum;
        mapPlayer2[iNum-1] = strPlayer;
        mapPlayer2[iNum] = strPlayer2;        
    }
    vector<string> answer(iSize,"");
    for(int i=0;i<iSize;++i)
    {
        answer[i] = mapPlayer2[i];
    }
    return answer;
}
