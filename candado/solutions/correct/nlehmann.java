import java.util.*;
import java.io.*;

class candado {
    static public void main(String argv[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int start[] = readCombination(new StringTokenizer(in.readLine()));
        int end[] = readCombination(new StringTokenizer(in.readLine()));

        int s = 0;
        for (int i = 0; i < 4; ++i) {
            s += Math.min((10 + start[i] - end[i]) % 10, (10 + end[i] - start[i]) % 10);
        }
        System.out.println(s);
    }

    static int[] readCombination(StringTokenizer st) {
        int arr[] = new int[4];
        for (int i = 0; i < 4; ++i) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        return arr;
    }
}
