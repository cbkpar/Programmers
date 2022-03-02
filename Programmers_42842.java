class Solution {
    public int[] solution(int brown, int yellow) {
        return solve(brown, yellow);
    }
    
    private static int[] solve(int brown, int yellow) {
        int[] ans = new int[2];
        int sz = (int) Math.sqrt(yellow);
        for (int i = 1; i <= sz; i++) {
            if (yellow % i != 0) continue;
            ans[0] = yellow / i + 2;
            ans[1] = i + 2;
            if ((ans[0] + ans[1] - 2) * 2 == brown) break;
        }
        return ans;
    }
}
