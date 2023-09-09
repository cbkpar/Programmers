#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(const vector<int>& vecQuery : queries)
    {
        swap(arr[vecQuery[0]],arr[vecQuery[1]]);
    }
    return arr;
}
