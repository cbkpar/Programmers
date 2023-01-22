#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int iSize1 = str1.length();
    int iSize2 = str2.length();
    for(int i=0;i<iSize1-iSize2+1;++i)
    {
        for(int j=0;j<iSize2;++j)
        {
            if(str1[i+j] != str2[j])
            {
                break;
            }
            if(j==iSize2-1)
            {
                return 1;
            }
        }
    }
    
    return 2;
}
