import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        Arrays.sort(phone_book);
        HashSet<String> set = new HashSet<>();
        int sz = phone_book.length;
        boolean chk = true;
        for(int i=0;i<sz;i++){
            int lsz = phone_book[i].length();
            for(int j=1;j<=lsz;j++){
                if(set.contains(phone_book[i].substring(0,j))){
                    chk = false;
                    break;
                }
            }
            set.add(phone_book[i]);
        }
        return chk;
    }
}
