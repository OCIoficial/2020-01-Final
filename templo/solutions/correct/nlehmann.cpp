#include <algorithm>
#include <climits>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

using Grid = vector<vector<int>>;

int M, N, K;

struct node {
  int t, i, j;
};

bool bfs(Grid grid) {
  queue<node> q;
  q.push({0, 0, 0});

  int c = 1;

  while (!q.empty()) {
    auto n = q.front();
    q.pop();

    if (n.t >= grid[n.i][n.j]) {
      continue;
    }

    if (n.i == M - 1 and n.j == N - 1) {
      return true;
    }

    grid[n.i][n.j] = n.t;

    vector<int> vi = {1, -1, 0, 0};
    vector<int> vj = {0, 0, -1, 1};
    for (int k = 0; k < 4; ++k) {
      int i = n.i + vi[k];
      int j = n.j + vj[k];
      if (i >= 0 and i < M and j >= 0 and j < N) {
        q.push({n.t + 1, i, j});
      }
    }
  }

  return false;
}

int main() {
  scanf("%d%d%d", &M, &N, &K);

  Grid grid = Grid(M, vector<int>(N, INT_MAX));

  while (K--) {
    int t, i, j;
    scanf("%d%d%d", &t, &i, &j);
    t--, i--, j--;

    grid[i][j] = min(grid[i][j], t);
  }

  printf(bfs(grid) ? "1\n" : "0\n");

  return 0;
}
