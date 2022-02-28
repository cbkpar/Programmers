import java.util.*;

class Solution {
    public int solution(int[] citations) {
        Arrays.sort(citations);
        int hidx = 0;
        int sz = citations.length;
        for (int i = 0; i < sz; i++) {
            if (citations[i] >= sz - i) {
                hidx = sz - i;
                break;
            }
        }
        return hidx;
    }
}
