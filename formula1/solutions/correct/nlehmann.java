import java.util.*;
import java.io.*;

class formula1 {
    static public void main(String argv[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(in.readLine());

        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());

        int vec[] = new int[N];
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < N; ++i) {
            vec[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i < N; ++i) {
            vec[i] = vec[i] + vec[i-1];
        }

        while(Q-- > 0) {
            st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            System.out.println(vec[b] - vec[a]);
        }
    }
}
