import java.util.*;
import java.io.*;

class Solution {
    public int solution(String str1, String str2) {
        int i,sz,mx,mi,ans;
		str1 = str1.toLowerCase(); 
		str2 = str2.toLowerCase(); 
		int[] a = new int[676];
		int[] b = new int[676];
		sz = str1.length();
		for(i=0;i<sz-1;i++) {
			if(str1.charAt(i)>='a'&&str1.charAt(i)<='z'&&str1.charAt(i+1)>='a'&&str1.charAt(i+1)<='z') {
				a[(str1.charAt(i)-'a')*26+(str1.charAt(i+1)-'a')]++;
			}
		}
		sz = str2.length();
		for(i=0;i<sz-1;i++) {
			if(str2.charAt(i)>='a'&&str2.charAt(i)<='z'&&str2.charAt(i+1)>='a'&&str2.charAt(i+1)<='z') {
				b[(str2.charAt(i)-'a')*26+(str2.charAt(i+1)-'a')]++;
			}
		}
		mi = mx = 0;
		for(i=0;i<676;i++) {
			mi += Math.min(a[i], b[i]);
			mx += Math.max(a[i], b[i]);
		}
		if(mx==0) {
			ans = 65536;
		}else {
			ans = (mi*65536)/mx;
		}
        return ans;
    }
}
