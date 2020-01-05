#include <cstdio>

using namespace std;

void read_cube(int cube[]) {
  for (int i = 0; i < 6; ++i) {
    scanf("%d", &cube[i]);
  }
}

bool equals(int cube1[], int cube2[], int offset = 0, int start = 0,
            int end = 6) {
  for (int i = start; i < end; ++i) {
    if (cube1[i] != cube2[(i + offset) % 6]) {
      return false;
    }
  }
  return true;
}

bool is_rot(int cube1[], int cube2[]) {
  if (cube1[0] != cube2[0] or cube1[1] != cube1[1])
    return false;

  for (int offset = 0; offset < 4; ++offset) {
    if (equals(cube1, cube2, offset, 2, 6))
      return true;
  }
  return false;
}

int main() {
  int cube1[6], cube2[6];
  read_cube(cube1);
  read_cube(cube2);

  if (is_rot(cube1, cube2)) {
    printf("1\n");
    return 0;
  }

  printf("0\n");

  return 0;
}
