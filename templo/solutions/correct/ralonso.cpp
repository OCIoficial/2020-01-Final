#include<bits/stdc++.h>

using namespace std;

int possible() {
  cout << 1 << endl;
  return 0;
}

int impossible() {
  cout << 0 << endl;
  return 0;
}

int main(int argc, char *argv[]) {
  int m, n, k;
  int t, i, j;

  cin >> m >> n >> k;

  // Fill the grid with 'infinity' and 0 on the edges to avoid invalid indices
  vector <vector <int> > grid (m + 2, vector<int>(n + 2, INT_MAX));

  for (i = 0; i < m + 2; ++i) {
    grid[i][0] = grid[i][n + 1] = 0;
  }

  for (j = 0; j < n + 2; ++j) {
    grid[0][j] = grid[m + 1][j] = 0;
  }

  // Mark the turn when a bomb falls on a given space. Such space may not be used from that turn on.
  for (int kk = 0; kk < k; ++kk) {
    cin >> t >> i >> j;
    if (grid[i][j] > t) { // Keep the earliest bomb
      grid[i][j] = t;
    }
  }

  queue <tuple <int,int,int> > bfs;
  tuple <int,int,int> tup;

  bfs.push(make_tuple(1, 1, 1));

  while (!bfs.empty()) {
    tup = bfs.front();
    bfs.pop();

    if (get<1>(tup) == m && get<2>(tup) == n) {  // Reached the exit; result depends on bomb
      return grid[get<1>(tup)][get<2>(tup)] >= get<0>(tup) ? possible() : impossible();
    }

    if (grid[get<1>(tup)][get<2>(tup)] <= get<0>(tup)) {  // Bombed space
      continue;
    }

    grid[get<1>(tup)][get<2>(tup)] = get<0>(tup);   // Store the turn

    // Expand the BFS frontier
    bfs.push(make_tuple(get<0>(tup) + 1, get<1>(tup) + 1, get<2>(tup)));
    bfs.push(make_tuple(get<0>(tup) + 1, get<1>(tup) - 1, get<2>(tup)));
    bfs.push(make_tuple(get<0>(tup) + 1, get<1>(tup), get<2>(tup) + 1));
    bfs.push(make_tuple(get<0>(tup) + 1, get<1>(tup), get<2>(tup) - 1));
  }

  return impossible();
}
