import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        HashMap<String, Integer> map = new HashMap<>();
        int ans = 1;
        int sz = clothes.length;
        for (int i = 0; i < sz; i++) {
            map.put(clothes[i][1], (map.containsKey(clothes[i][1]) ? map.get(clothes[i][1]) : 0) + 1);
        }
        for (String key : map.keySet()) {
            ans *= map.get(key) + 1;
        }
        return ans - 1;
    }
}
