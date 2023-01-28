#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int iSize = numbers.size();
    answer.resize(iSize);
    stack<int> stNumber;
    for(int i=iSize-1;i>=0;--i)
    {
        while(stNumber.size()>0)
        {
            if(stNumber.top()<=numbers[i])
            {
                stNumber.pop();
            }
            else
            {
                break;
            }
        }
        if(stNumber.size()==0)
        {
            answer[i] = -1;
        }
        else
        {
            answer[i] = stNumber.top();
        }
        stNumber.push(numbers[i]);
    }
    return answer;
}
