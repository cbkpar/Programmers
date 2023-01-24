#include <string>
#include <vector>

using namespace std;

int gcd(int iA, int iB)
{
    if(iB%iA == 0) return iA;
    return gcd(iB%iA, iA);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int iMolecule = numer1 * denom2 + numer2 * denom1;
    int iDenominator = denom1 * denom2;
    
    int iGCD = (iMolecule<iDenominator?gcd(iMolecule,iDenominator):gcd(iDenominator,iMolecule));
    
    answer.push_back(iMolecule/iGCD);
    answer.push_back(iDenominator/iGCD);
    return answer;
}
