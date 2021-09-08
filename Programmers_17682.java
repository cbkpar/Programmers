import java.util.*;

class Solution {
    public int solution(String dartResult) {
        StringTokenizer a = new StringTokenizer(dartResult.replaceAll("[^0-9]"," "));
		StringTokenizer b = new StringTokenizer(dartResult.replaceAll("[0-9]"," "));
		int i;
		int[] arr = new int[3];
		for(i=0;i<3;i++) arr[i] = Integer.parseInt(a.nextToken());
		for(i=0;i<3;i++) {
			String str = b.nextToken();
			if(str.contains("D")) arr[i] = arr[i]*arr[i];
			if(str.contains("T")) arr[i] = arr[i]*arr[i]*arr[i];
			if(str.contains("*")) {
				arr[i] = arr[i]*2;
				if(i>=1) arr[i-1] = arr[i-1]*2;
			}
			if(str.contains("#")) arr[i] = arr[i]*-1;
		}
        return arr[0]+arr[1]+arr[2];
    }
}
