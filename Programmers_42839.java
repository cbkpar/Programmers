import java.util.*;

class Solution {
    
    static boolean[] isprime;
    static int[] arr;
    static int sz;
    static HashSet<Integer> set = new HashSet<>();
    static boolean[] visited;
    
    public int solution(String numbers) {
        sz = numbers.length();
        visited = new boolean[sz];
        arr = new int[sz];
        for (int i = 0; i < sz; i++) arr[i] = numbers.charAt(i) - '0';

        isprime = new boolean[10000000];
        isprime[0] = isprime[1] = true;
        for (int i = 2; i * i < 10000000; i++) {
            for (int j = i * i; j < 10000000; j += i) {
                isprime[j] = true;
            }
        }
        
        return dfs(0, 0);
    }
    
    private static int dfs(int num, int k) {
        int cnt = 0;
        for (int i = 0; i < sz; i++) {
            if (visited[i]) continue;
            int tmp = num * 10 + arr[i];
            visited[i] = true;
            if (!isprime[tmp] && !set.contains(tmp)) {
                set.add(tmp);
                cnt++;
            }
            cnt += dfs(tmp, k + 1);
            visited[i] = false;
        }
        return cnt;
    }
}
