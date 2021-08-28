import java.util.*;
import java.io.*;

class Solution {
    public int solution(String word, String[] pages) {
		int i,j,t,k,sz,ssz,index;
		double mx;
        word = word.toLowerCase();
		sz = pages.length;
		ArrayList<String>[] arr = new ArrayList[sz];
		int[] score = new int[sz];
		double[] total = new double[sz];
		for(i=0;i<sz;i++) arr[i] = new ArrayList<String>();
		HashMap<String,Integer> map = new HashMap<String,Integer>();
		for(i=0;i<sz;i++) {
			String str = pages[i].toLowerCase();
			String root = substringBetween(str,"meta property=\"og:url\" content=\"","\"");
			map.put(root,i);
			t = 0;
			while(true) {
				k = str.substring(t).indexOf("<a href=\"")+t+1;
				if(k==t) break;
				t = k;
				String link = substringBetween(str.substring(k-1),"<a href=\"","\"");
				if(link==null) break;
				arr[i].add(link);
			}
			StringTokenizer st = new StringTokenizer(str.replaceAll("[^a-z ]", " "));
			while(st.hasMoreTokens()) if(st.nextToken().equals(word)) score[i]++;
		}
		for(i=0;i<sz;i++) {
			total[i] += score[i];
			ssz = arr[i].size();
			for(j=0;j<ssz;j++) {
				if(map.containsKey(arr[i].get(j))) {
					t = map.get(arr[i].get(j));
					total[t] += (double)score[i]/ssz;
				}
			}
		}
		index = -1;
		mx = -1;
		for(i=0;i<sz;i++) {
			if(total[i]>mx) {
				index = i;
				mx = total[i];
			}
		}
        return index;
    }
    
    public static String substringBetween(String str, String open, String close) {
	    if (str == null || open == null || close == null) {
	       return null;
	    }
	    int start = str.indexOf(open);
	    if (start != -1) {
	       int end = str.indexOf(close, start + open.length());
	       if (end != -1) {
	          return str.substring(start + open.length(), end);
	       }
	    }
	    return null;
	}
}
