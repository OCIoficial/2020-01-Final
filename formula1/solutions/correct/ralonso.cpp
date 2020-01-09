#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, q, r1, r2;
  cin >> n >> q;

  vector <int> times(n + 1);
  vector <int> acc(n + 1);

  for (int it = 1; it <= n; ++it) {
    cin >> times[it];
  }

  acc[1] = 0;
  for (int it = 2; it <= n; ++it) {
    acc[it] = acc[it - 1] + times[it];
  }

  for (int it = 0; it < q; ++it) {
    cin >> r1 >> r2;
    cout << acc[r2] - acc[r1] << endl;
  }

  return 0;
}
