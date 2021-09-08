class Solution {
    public int solution(int left, int right) {
        int ans = 0;
        for(int i=left;i<=right;i++){
            int sq = (int)Math.sqrt(i);
            if(i==sq*sq){
                ans -= i;
            }else{
                ans += i;
            }
        }
        return ans;
    }
}
