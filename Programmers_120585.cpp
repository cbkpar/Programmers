#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    for(int iHeight : array)
    {
        if(iHeight > height)
        {
            ++answer;
        }
    }
    return answer;
}
