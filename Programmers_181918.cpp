#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    stack<int> stackNum;
    int iLen = arr.size();
    for(int i=iLen-1;i>=0;--i)
    {
        if(stackNum.empty())
        {
            stackNum.push(arr[i]);
        }
        else if(stackNum.top() > arr[i])
        {
            stackNum.push(arr[i]);
        }
    }
    while(!stackNum.empty())
    {
        stk.push_back(stackNum.top());
        stackNum.pop();
    }
    return stk;
}
