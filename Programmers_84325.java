import java.util.*;
import java.io.*;

class Solution {
    public String solution(String[] table, String[] languages, int[] preference) {
        int i,j,k,sz,mx;
		String ans;
		String[] name = new String[5];
		String[][] subject = new String[5][5];
		for(i=0;i<5;i++) {
			StringTokenizer st = new StringTokenizer(table[i]);
			name[i] = st.nextToken();
			for(j=0;j<5;j++) {
				subject[i][j] = st.nextToken();
			}
		}
		
		int[] score = new int[5];
		sz = languages.length;
		for(i=0;i<sz;i++) {
			for(j=0;j<5;j++) {
				for(k=0;k<5;k++) {
					if(languages[i].equals(subject[j][k])) {
						score[j] += (5-k)*preference[i];
					}
				}
			}
		}
		ans = name[0];
		mx = score[0];
		for(i=1;i<5;i++) {
			if(mx<score[i]) {
				mx = score[i];
				ans = name[i];
			}else if(mx==score[i]) {
				if(ans.compareTo(name[i])>0) {
					ans = name[i];
				}
			}
		}
        return ans;
    }
}
