import java.util.*;

class Solution {
    public int solution(int N, int number) {
        int[] dp = new int[32001];
        HashSet<Integer> set = new HashSet<>();
        int tmp = 0;
        ArrayList<Integer>[] arr = new ArrayList[9];
        for (int i = 1; i <= 8; i++) {
            arr[i] = new ArrayList<Integer>();
            tmp = tmp * 10 + N;
            arr[i].add(tmp);
            set.add(tmp);
            if (tmp <= 32000 && tmp >= 0) dp[tmp] = i;
        }
        for (int k = 2; k <= 8; k++) {
            for (int i = 1; i < k; i++) {
                int j = k - i;
                int psz = arr[i].size();
                int qsz = arr[j].size();
                for (int p = 0; p < psz; p++) {
                    for (int q = 0; q < qsz; q++) {
                        tmp = arr[i].get(p) + arr[j].get(q);
                        if (!set.contains(tmp)) {
                            set.add(tmp);
                            arr[k].add(tmp);
                            if (tmp <= 32000 && tmp >= 0) dp[tmp] = k;
                        }
                        tmp = arr[i].get(p) - arr[j].get(q);
                        if (!set.contains(tmp)) {
                            set.add(tmp);
                            arr[k].add(tmp);
                            if (tmp <= 32000 && tmp >= 0) dp[tmp] = k;
                        }
                        tmp = arr[i].get(p) * arr[j].get(q);
                        if (!set.contains(tmp)) {
                            set.add(tmp);
                            arr[k].add(tmp);
                            if (tmp <= 32000 && tmp >= 0) dp[tmp] = k;
                        }
                        if(arr[j].get(q)==0) continue;
                        tmp = arr[i].get(p) / arr[j].get(q);
                        if (!set.contains(tmp)) {
                            set.add(tmp);
                            arr[k].add(tmp);
                            if (tmp <= 32000 && tmp >= 0) dp[tmp] = k;
                        }
                    }
                }
            }
        }
        return (dp[number] == 0 ? -1 : dp[number]);
    }
}
