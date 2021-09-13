class Solution {
    public int solution(int[] numbers) {
        int sz = numbers.length;
        int ans = 45;
        for(int i=0;i<sz;i++) ans -= numbers[i];
        return ans;
    }
}
