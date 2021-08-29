import java.util.*;
import java.util.regex.*;
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
        Pattern pa = Pattern.compile("(meta property=\"og:url\" content=\")(.*?)(\")");
        Pattern pb = Pattern.compile("(<a href=\")(.*?)(\")");
        for(i=0;i<sz;i++) {
			String str = pages[i].toLowerCase();
            Matcher m = pa.matcher(str);
            m.find();
			map.put(m.group(2),i);
            m = pb.matcher(str);
			while(m.find()) arr[i].add(m.group(2));
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
