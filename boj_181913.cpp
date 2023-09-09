#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    for(const vector<int>& vecQuery : queries)
    {
        int iS = vecQuery[0];
        int iE = vecQuery[1];
        while(iS < iE)
        {
            swap(my_string[iS],my_string[iE]);
            ++iS;
            --iE;
        }
    }
    return my_string;
}
