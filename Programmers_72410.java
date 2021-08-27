import java.util.*;
import java.io.*;

class Solution {
    public String solution(String new_id) {
		int sz,i,mi;
		String ans = "";
		new_id = new_id.toLowerCase();
		new_id = new_id.replaceAll("[^a-z0-9-_.]", "");
		ArrayList<Character> arr = new ArrayList<Character>();
		ArrayList<Character> ch = new ArrayList<Character>();
		sz = new_id.length();
		if(sz!=0) arr.add(new_id.charAt(0));
		for(i=1;i<sz;i++) {
			if(new_id.charAt(i)=='.'&&new_id.charAt(i-1)=='.') continue;
			arr.add(new_id.charAt(i));
		}
		sz = arr.size();
		if(sz!=0) if(arr.get(sz-1)=='.') sz--;
		if(sz!=0) if(arr.get(0)=='.') {
			mi = Math.min(sz,16);
			for(i=1;i<mi;i++) ch.add(arr.get(i));
		}else {
			mi = Math.min(sz,15);
			for(i=0;i<mi;i++) ch.add(arr.get(i));
		}
		if(ch.size()==0) ch.add('a');
		sz = ch.size();
		if(ch.get(sz-1)=='.') sz--;
		if(sz==1) {
			ans = ""+ch.get(0)+ch.get(0)+ch.get(0);
		}else if(sz==2) {
			ans = ""+ch.get(0)+ch.get(1)+ch.get(1);
		}else {
			for(i=0;i<sz;i++) ans = ans + ch.get(i);
		}
        return ans;
    }
}
