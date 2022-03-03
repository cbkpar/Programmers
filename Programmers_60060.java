import java.util.*;

class Solution {
    public int[] solution(String[] words, String[] queries) {
        Trie[][] map = new Trie[10001][2];
        int[] cnt = new int[10001];
        for (int i = 1; i <= 10000; i++) map[i][0] = new Trie();
        for (int i = 1; i <= 10000; i++) map[i][1] = new Trie();
        for (String str : words) {
            int sz = str.length();
            cnt[sz]++;
            map[sz][0].insert(str);
            String tmpstr = "";
            for (int i = sz - 1; i >= 0; i--) tmpstr += str.charAt(i);
            map[sz][1].insert(tmpstr);
        }
        int qsz = queries.length;
        int[] ans = new int[qsz];
        for (int i = 0; i < qsz; i++) {
            int dir = queries[i].charAt(0) == '?' ? 1 : 0;
            int sz = queries[i].length();
            String tmpstr = "";
            if (queries[i].charAt(0) != '?') {
                for (int j = 0; j < sz; j++) {
                    if (queries[i].charAt(j) == '?') break;
                    tmpstr += queries[i].charAt(j);
                }
            } else {
                for (int j = sz - 1; j >= 0; j--) {
                    if (queries[i].charAt(j) == '?') break;
                    tmpstr += queries[i].charAt(j);
                }
            }
            ans[i] = map[sz][dir].search(tmpstr);
            if(tmpstr.equals("")) ans[i] = cnt[sz];
        }
        return ans;
    }
}

class Trie {
    Node n = new Node();

    void insert(String str) {
        Node node = this.n;
        for (int i = 0; i < str.length(); i++) {
            node = node.childeNode.computeIfAbsent(str.charAt(i), key -> new Node());
            node.cnt++;
        }
    }

    int search(String str) {
        Node node = this.n;
        for (int i = 0; i < str.length(); i++) {
            node = node.childeNode.getOrDefault(str.charAt(i), null);
            if (node == null) return 0;
        }
        return node.cnt;
    }
}

class Node {
    Map<Character, Node> childeNode = new HashMap<Character, Node>();
    int cnt = 0;

}
