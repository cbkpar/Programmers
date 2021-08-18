import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
		int i,sz,t;
		String name;
		HashMap<String,Integer> money = new HashMap<String,Integer>();
		HashMap<String,String> node = new HashMap<String,String>();
		sz = enroll.length;
		for(i=0;i<sz;i++) {
			money.put(enroll[i], 0);
			if(money.containsKey(referral[i])) node.put(enroll[i],referral[i]);
		}
		sz = seller.length;
		for(i=0;i<sz;i++) {
			t = amount[i]*100;
			name = seller[i];
			while(t>0) {
				money.put(name,money.get(name)+(t-t/10));
				t /= 10;
				if(!node.containsKey(name)) break;
				name = node.get(name);
			}
		}
		sz = enroll.length;
		int[] answer = new int[sz];
		for(i=0;i<sz;i++) answer[i] = money.get(enroll[i]);
		return answer;
    }
}
