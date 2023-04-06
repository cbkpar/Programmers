#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long lNum : numbers)
    {
        long long lTemp = lNum;
        long long lCount = 0;
        while(true)
        {
            if(lTemp%2==0) break;
            ++lCount;
            lTemp /= 2;
        }
        lNum += 1LL << lCount;
        if(lCount >= 1) lNum -= 1LL << (lCount-1);
        answer.push_back(lNum);
    }
    
    return answer;
}
