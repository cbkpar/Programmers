#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string strId = id_pw[0];
    string strPw = id_pw[1];
    for(vector<string> arrDB : db)
    {
        if(arrDB[0] == strId)
        {
            if(arrDB[1] == strPw)
            {
                return "login";
            }
            else
            {
                return "wrong pw";
            }
        }
    }
    return "fail";
}
