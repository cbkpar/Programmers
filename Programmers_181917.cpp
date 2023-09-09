#include <string>
#include <vector>

using namespace std;

bool OperDownArrow(bool bA, bool bB)
{
    if(bA || bB) return true;
    return false;
}

bool OperUpArrow(bool bA, bool bB)
{
    if(bA && bB) return true;
    return false;
}

bool solution(bool x1, bool x2, bool x3, bool x4) {
    return OperUpArrow(OperDownArrow(x1,x2),OperDownArrow(x3,x4));
}
