#include <string>
#include <vector>

using namespace std;

int arrCountA[10001] = {0,};
int arrCountB[10001] = {0,};

int solution(vector<int> topping) {
    int answer = 0;
    int iCountA = 0;
    int iCountB = 0;
    for(int iNum : topping)
    {
        if(arrCountB[iNum]==0)
        {
            ++iCountB;
        }
        ++arrCountB[iNum];
    }
    for(int iNum : topping)
    {
        if(arrCountA[iNum]==0)
        {
            ++iCountA;
        }
        ++arrCountA[iNum];
        if(arrCountB[iNum]==1)
        {
            --iCountB;
        }
        --arrCountB[iNum];
        if(iCountA == iCountB)
        {
            ++answer;
        }
    }
    return answer;
}
