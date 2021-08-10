import java.util.ArrayList;
import java.util.Collections;

class Solution {
    
    static ArrayList<Integer>[] arr = new ArrayList[17576];
    static ArrayList<Boolean>[] visited = new ArrayList[17576];
    static int[] ans;
    static String[] answer;
    static boolean chk;
    static int sz;
    
    public String[] solution(String[][] tickets) {
        sz = tickets.length;
        for(int i=0;i<17576;i++) arr[i] = new ArrayList<Integer>();
        for(int i=0;i<17576;i++) visited[i] = new ArrayList<Boolean>();
        for(int i=0;i<sz;i++){
            int a = (tickets[i][0].charAt(0)-'A')*676+(tickets[i][0].charAt(1)-'A')*26+(tickets[i][0].charAt(2)-'A');
            int b = (tickets[i][1].charAt(0)-'A')*676+(tickets[i][1].charAt(1)-'A')*26+(tickets[i][1].charAt(2)-'A');
            arr[a].add(b);
        }
        for(int i=0;i<17576;i++) Collections.sort(arr[i]);
        for(int i=0;i<17576;i++) for(int j=0;j<arr[i].size();j++) visited[i].add(false);
        chk = false;
        ans = new int[sz];
        answer = new String[sz+1];
        answer[0] = "ICN";
        dfs(5473,0);
        return answer;
    }
    
    public static void dfs(int n, int k){
        if(chk) return;
        if(k==sz){
            for(int i=0;i<sz;i++) answer[i+1] = (char)(ans[i]/676+'A')+""+(char)((ans[i]%676)/26+'A')+""+(char)(ans[i]%26+'A');
            chk = true;
            return;
        }
        for(int i=0;i<arr[n].size();i++){
            if(!visited[n].get(i)){
                visited[n].set(i,true);
                ans[k] = arr[n].get(i);
                dfs(arr[n].get(i),k+1);
                visited[n].set(i,false);
            }
        }
    }
}
