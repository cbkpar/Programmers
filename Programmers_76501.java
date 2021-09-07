class Solution {
    public int solution(int[] absolutes, boolean[] signs) {
        int sz = absolutes.length;
        int ans = 0;
        for(int i=0;i<sz;i++) ans += absolutes[i] * (signs[i]?1:-1);
        return ans;
    }
}
