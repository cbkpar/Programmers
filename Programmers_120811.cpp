#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    sort(array.begin(), array.end());
    int iSize = array.size();
    int answer = array[iSize/2];
    return answer;
}
