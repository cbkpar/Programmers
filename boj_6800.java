import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {


    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        HashMap<String, String> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String ch = st.nextToken();
            String code = st.nextToken();
            map.put(code, ch);
        }
        String str = br.readLine();
        String tmp = "";
        int sz = str.length();
        for (int i = 0; i < sz; i++) {
            tmp = tmp + str.charAt(i);
            if (map.containsKey(tmp)) {
                sb.append(map.get(tmp));
                tmp = "";
            }
        }
        System.out.println(sb);
    }
}
