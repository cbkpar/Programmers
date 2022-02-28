import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        HashMap<String, Integer> map = new HashMap<>();
        int sz = genres.length;
        int cnt = 0;
        ArrayList<genre> genarr = new ArrayList<>();
        for (int i = 0; i < sz; i++) {
            if (!map.containsKey(genres[i])) {
                genarr.add(new genre(plays[i], new ArrayList<>()));
                genarr.get(cnt).arr.add(new music(i, plays[i]));
                map.put(genres[i], cnt++);
            } else {
                int k = map.get(genres[i]);
                genarr.get(k).plus(plays[i]);
                genarr.get(k).arr.add(new music(i, plays[i]));
            }
        }
        Collections.sort(genarr, new Comparator<genre>() {
            @Override
            public int compare(genre o1, genre o2) {
                return o2.total - o1.total;
            }
        });
        ArrayList<Integer> ans = new ArrayList<>();
        for (genre gen : genarr) {
            Collections.sort(gen.arr, new Comparator<music>() {
                @Override
                public int compare(music o1, music o2) {
                    if (o1.play != o2.play) return o2.play - o1.play;
                    return o1.n - o2.n;
                }
            });
            ans.add(gen.arr.get(0).n);
            if (gen.arr.size() >= 2) ans.add(gen.arr.get(1).n);
        }
        sz = ans.size();
        int[] answer = new int[sz];
        for (int i = 0; i < sz; i++) answer[i] = ans.get(i);
        return answer;
    }
}

class genre {
    int total;
    ArrayList<music> arr;

    public genre(int total, ArrayList<music> arr) {
        this.total = total;
        this.arr = arr;
    }

    public void plus(int n) {
        this.total += n;
    }
}

class music {
    int n;
    int play;

    public music(int n, int play) {
        this.n = n;
        this.play = play;
    }
}
