#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void read_combination(vector<int> &vec) {
  for (int i = 0; i < 4; ++i) {
    scanf("%d", &vec[i]);
  }
}

int main() {
  vector<int> start(4);
  vector<int> end(4);
  read_combination(start);
  read_combination(end);

  int s = 0;
  for (int i = 0; i < 4; ++i) {
    if (start[i] > end[i]) {
      s += min(start[i] - end[i], 10 + end[i] - start[i]);
    } else {
      s += min(end[i] - start[i], 10 + start[i] - end[i]);
    }
  }
  printf("%d\n", s);

  return 0;
}
