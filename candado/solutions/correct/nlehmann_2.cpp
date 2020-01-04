#include <algorithm>
#include <cstdio>
#include <vector>

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
     s += min((10 + start[i] - end[i]) % 10, (10 + end[i] - start[i]) % 10);
  }
  printf("%d\n", s);

  return 0;
}
