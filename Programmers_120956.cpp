#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;    
    for(string str: babbling)
    {
        int iSize = str.length();
        int iCount = 0;
        for(int i=0;i<iSize;)
        {
            if(i+2<iSize && str[i] =='a' && str[i+1] =='y' && str[i+2] =='a')
            {
                iCount += 3;
                i+=3;
                continue;
            }
            if(i+1<iSize && str[i] =='y' && str[i+1] =='e')
            {
                iCount += 2;
                i+=2;
                continue;
            }
            if(i+2<iSize && str[i] =='w' && str[i+1] =='o' && str[i+2] =='o')
            {
                iCount += 3;
                i+=3;
                continue;
            }
            if(i+1<iSize && str[i] =='m' && str[i+1] =='a')
            {
                iCount += 2;
                i+=2;
                continue;
            }
            ++i;
        }
        if(iCount == iSize)
        {
            ++answer;
        }
        
    }
    return answer;
}
