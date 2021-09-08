import java.util.Arrays;

class Solution {
    public int solution(int[] nums) {
        int answer = 1;
        int sz = nums.length;
        Arrays.sort(nums);
        for(int i=1;i<sz;i++) if(nums[i-1]!=nums[i]) answer++;
        answer = Math.min(answer, sz/2);
        return answer;
    }
}
