#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int N, Q;
  scanf("%d%d", &N, &Q);

  vector<int> vec(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &vec[i]);
  }

  for (int i = 1; i < N; ++i) {
    vec[i] = vec[i] + vec[i-1];
  }

  while(Q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    printf("%d\n", vec[b] - vec[a]);
  }
}
