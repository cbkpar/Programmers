#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    if(sides[0] < sides[1])
    {
        return sides[0] * 2 -1;
    }
    else
    {
        return sides[1] * 2 -1;
    }
    return 0;
}
