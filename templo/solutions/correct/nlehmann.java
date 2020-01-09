import java.util.*;
import java.io.*;


class bombas {
    static int grid[][];
    static int M, N;
    static public void main(String args[]) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(in.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        int K = Integer.parseInt(in.readLine());

        grid = new int[M][N];
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                grid[i][j] = Integer.MAX_VALUE;
            }
        }

        for (int k = 0; k < K; ++k) {
            st = new StringTokenizer(in.readLine());
            int t = Integer.parseInt(st.nextToken()) - 1;
            int i = Integer.parseInt(st.nextToken()) - 1;
            int j = Integer.parseInt(st.nextToken()) - 1;

            grid[i][j] = Math.min(grid[i][j], t);
        }

        System.out.println(bfs() ? 1 : 0);
    }

    static boolean bfs() {
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(0, 0, 0));

        while (!q.isEmpty()) {
            Node n = q.remove();

            if (n.i == M - 1 && n.j == N - 1)
                return true;

            if (grid[n.i][n.j] <= n.t)
                continue;

            grid[n.i][n.j] = n.t;

            int di[] = {-1, 1, 0, 0};
            int dj[] = {0, 0, -1, 1};
            for (int k = 0; k < 4; ++k) {
                int i = n.i + di[k];
                int j = n.j + dj[k];
                if (i >= 0 && i < M && j >= 0 && j < N) {
                    q.offer(new Node(n.t + 1, i, j));
                }
            }
        }

        return false;
    }
}

class Node {
    int t, i, j;

    public Node(int t, int i, int j) {
        this.t = t;
        this.i = i;
        this.j = j;
    }
}
