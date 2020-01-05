#include <cstdio>

using namespace std;

void read_cube(int cube[]) {
  for (int i = 0; i < 6; ++i) {
    scanf("%d", &cube[i]);
  }
}

bool all_the_same(int cube[]) {
  for (int i = 0; i < 5; ++i) {
    if (cube[i] != cube[i+1]) {
      return false;
    }
  }
  return true;
}

int main() {
  int cube1[6], cube2[6];
  read_cube(cube1);
  read_cube(cube2);

  if (all_the_same(cube1) and all_the_same(cube2) and cube1[0] == cube2[0]) {
    printf("1\n");
    return 0;
  }

  printf("0\n");

  return 0;
}
