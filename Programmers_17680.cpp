#include <string>
#include <vector>
#include <list>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> listCache;
    for(string str:cities)
    {
        string newString = "";
        int iSize = str.length();
        newString.resize(iSize);
        for(int i=0;i<iSize;++i)
        {
            if(str[i]>='A'&&str[i]<='Z')
            {
                newString[i]  = (char)(str[i]-'A'+'a');
            }
            else
            {
                newString[i]  = str[i];
            }
        }
        bool bFound = false;
        for(auto iter = listCache.begin();iter != listCache.end();++iter)
        {
            if((*iter)==newString)
            {
                bFound = true;
                listCache.erase(iter);
                break;
            }
        }
        answer += (bFound?1:5);
        listCache.push_front(newString);
        if(listCache.size() > cacheSize)
        {
            listCache.pop_back();
        }
    }
    return answer;
}
