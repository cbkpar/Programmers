import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        int sz = record.length;
		int i;
        Stack<Integer> a = new Stack<>(); 
        Stack<String> b = new Stack<>(); 
        HashMap<String,String> map = new HashMap<>();
		for(i=sz-1;i>=0;i--) {
			StringTokenizer st = new StringTokenizer(record[i]);
			String str = st.nextToken();
			if(str.equals("Change")) {
				str = st.nextToken();
				if(map.containsKey(str)) continue;
				map.put(str,st.nextToken());
			}else if(str.equals("Enter")) {
				str = st.nextToken();
				a.add(1);
				b.add(str);
				if(!map.containsKey(str)) map.put(str,st.nextToken());
			}else {
				str = st.nextToken();
				a.add(0);
				b.add(str);
			}
		}
		sz = a.size();
		String[] ans = new String[sz];
		for(i=0;i<sz;i++) {
			if(a.pop()==1) {
				ans[i] = map.get(b.pop())+"님이 들어왔습니다.";
			}else {
				ans[i] = map.get(b.pop())+"님이 나갔습니다.";
			}
		}
		return ans;
    }
}
