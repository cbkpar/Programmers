import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        int[] num = new int[1001];
        for(int n:numbers) num[n]++;
        if(num[0] == numbers.length) return "0";
        ArrayList<number> arr = new ArrayList<>();
        for(int i=0;i<=1000;i++){
            if(num[i]==0) continue;
            arr.add(new number(i,convert(i),num[i]));
        }
        Collections.sort(arr, new Comparator<number>(){
           @Override
           public int compare(number o1, number o2){
               return o2.compare - o1.compare;
           }
        });
        StringBuilder sb = new StringBuilder();
        for(number N:arr){
            int sz = N.cnt;
            while(sz-->0) sb.append(N.n);
        }
        return sb.toString();
    }
    
    private static int convert(int n){
        if(n<10){
            return n*1111;
        }else if(n<100){
            return n*101;
        }else if(n<1000){
            return n*10+n/100;
        }else{
            return n;
        }
    }
}

class number {
    int n;
    int compare;
    int cnt;

    public number(int n, int compare, int cnt) {
        this.n = n;
        this.compare = compare;
        this.cnt = cnt;
    }
}
