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

  while (Q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int s = 0;
    for (int i = a; i < b; ++i) {
      s += vec[i];
    }
    printf("%d\n", s);
  }
}
