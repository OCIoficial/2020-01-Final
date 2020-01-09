#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int N = inf.readInt(2, 1000, "N");
  inf.readSpace();
  int Q = inf.readInt(1, 1000, "Q");
  inf.readEoln();

  long s = 0;
  for (int i = 0; i < N; ++i) {
    if (i > 0) {
      inf.readSpace();
    }
    s += inf.readInt(0, 1000000000);
    ensuref(s <= 1000000000, "Result must be less than 10^9");
  }
  inf.readEoln();

  for (int i = 0; i < Q; ++i) {
    int a = inf.readInt(1, N, "a");
    inf.readSpace();
    inf.readInt(a + 1, N, "b");
    inf.readEoln();
  }

  inf.readEof();
}
