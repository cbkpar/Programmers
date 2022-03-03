class Solution {
    public int solution(int[] people, int limit) {
        int cnt = 0;
        int[] arr = new int[241];
        for (int p : people) arr[p]++;
        for (int i = limit; i >= 40; i--) {
            if (arr[i] <= 0) continue;
            while (arr[i]-- > 0) {
                cnt++;
                for (int j = limit - i; j >= 40; j--) {
                    if (arr[j] <= 0) continue;
                    arr[j]--;
                    break;
                }
            }
        }
        return cnt;
    }
}
