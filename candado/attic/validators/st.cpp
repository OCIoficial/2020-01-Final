#include "testlib.h"

using namespace std;

int main() {
  registerValidation();

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (j > 0) {
        inf.readSpace();
      }
      inf.readInt(0, 9);
    }
    inf.readEoln();
  }

  inf.readEof();
}
