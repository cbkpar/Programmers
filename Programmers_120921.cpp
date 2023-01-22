#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    string str = B + B;
    int iSize = A.length();
    for(int i=0;i<iSize;++i)
    {
        for(int j=0;j<iSize;++j)
        {
            if(A[j] != str[i+j])
            {
                break;
            }
            if(j==iSize-1)
            {
                return i;
            }
        }
    }
    return -1;
}
