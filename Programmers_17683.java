import java.util.*;
import java.io.*;

class Solution {
    static int[] pi;
	  static char[] p;
     
    public String solution(String m, String[] musicinfos) {
        int sz,i,j,time,lsz,t,mx;
		String name,lyric,str,ans;
		p = convert(m).toCharArray();
		getPI();
		sz = musicinfos.length;
		ans = "(None)";
		mx = -1;
		for(i=0;i<sz;i++) {
			StringTokenizer st = new StringTokenizer(musicinfos[i],",");
			time = gettime(st.nextToken(),st.nextToken());
			name = st.nextToken();
			StringBuilder sb = new StringBuilder();
			lyric = convert(st.nextToken());
			lsz = lyric.length();
			t = time/lsz;
			while(t-->0) sb.append(lyric);
			for(j=0;j<time%lsz;j++) sb.append(lyric.charAt(j));
			str = sb.toString();
			if(KMP(str)==1) {
				if(time>mx) {
					mx = time;
					ans = name;
				}
			}
		}
        return ans;
    }
    
    public static String convert(String str) {
		StringBuilder sb = new StringBuilder();
		int sz = str.length();
		for(int i=0;i<sz-1;i++) {
			if(str.charAt(i+1)=='#') {
				sb.append((char)(str.charAt(i)-'A'+'a'));
				i++;
			}else {
				sb.append(str.charAt(i));
			}
		}
		if(str.charAt(sz-1)!='#') sb.append(str.charAt(sz-1));
		return sb.toString();
	}
	
	public static int gettime(String a, String b) {
		int time = ((b.charAt(0)-a.charAt(0))*10+b.charAt(1)-a.charAt(1))*60;
		time += (b.charAt(3)-a.charAt(3))*10+b.charAt(4)-a.charAt(4);
		return time;
	}
	
	public static void getPI() {
		pi = new int[p.length];
		int j = 0;
		int sz = p.length;
		for(int i=1;i<sz;i++) {
			while(j>0&&p[i]!=p[j]) j = pi[j-1];
			if(p[i]==p[j]) pi[i] = ++j;
		}
	}
	
	public static int KMP(String str) {
		char[] s = str.toCharArray();
		int j = 0;
		int sz = str.length();
		for(int i=0;i<sz;i++) {
			while(j>0&&s[i]!=p[j]) j = pi[j-1];
			if(s[i]==p[j]) {
				if(j==p.length-1) return 1;
				j++;
			}
		}
		return 0;
	}
}
