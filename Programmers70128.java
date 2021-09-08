class Solution {
    public int solution(int[] a, int[] b) {
        int sz = a.length;
        int ans = 0;
        for(int i=0;i<sz;i++) ans += a[i]*b[i];
        return ans;
    }
}
