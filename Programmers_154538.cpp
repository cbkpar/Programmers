#include <string>
#include <vector>
#include <queue>

using namespace std;

bool arrVisited[1000001] = {false,};

int solution(int x, int y, int n) {
    queue<int> qNumber;
    qNumber.push(x);
    arrVisited[x] = true;
    
    int iCount = 0;
    while(qNumber.size()>0)
    {
        int iSize = qNumber.size();
        while(iSize--)
        {
            int iNum = qNumber.front();
            qNumber.pop();
            if(iNum == y) return iCount;
            if(iNum+n<=1000000&&!arrVisited[iNum+n])
            {
                arrVisited[iNum+n] = true;
                qNumber.push(iNum+n);
            }
            if(iNum*2<=1000000&&!arrVisited[iNum*2])
            {
                arrVisited[iNum*2] = true;
                qNumber.push(iNum*2);
            }
            if(iNum*3<=1000000&&!arrVisited[iNum*3])
            {
                arrVisited[iNum*3] = true;
                qNumber.push(iNum*3);
            }
        }
        ++iCount;
    }
    
    return -1;
}
