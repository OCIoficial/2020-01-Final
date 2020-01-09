#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int M = inf.readInt(1, 1000, "M");
  inf.readSpace();
  int N = inf.readInt(2, 1000, "N");
  inf.readEoln();

  int K = inf.readInt(0, M * N, "K");
  inf.readEoln();

  for (int k = 0; k < K; ++k) {
    inf.readInt(1, M * N, "t");
    inf.readSpace();
    int i = inf.readInt(1, M, "i");
    inf.readSpace();
    int j = inf.readInt(1, N, "j");
    inf.readEoln();

    ensuref(i != 1 or j != 1, "No rock on first cell");
    ensuref(i != M or j != N, "No rock on last cell");
  }

  inf.readEof();
}
