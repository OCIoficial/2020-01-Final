#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int s1, s2, s3, s4, t1, t2, t3, t4;

  cin >> s1 >> s2 >> s3 >> s4 >> t1 >> t2 >> t3 >> t4;

  int diff1, diff2, diff3, diff4;
  
  diff1 = abs(t1 - s1);
  diff2 = abs(t2 - s2);
  diff3 = abs(t3 - s3);
  diff4 = abs(t4 - s4);
  
  printf(
    "%d\n",
    min(diff1, 10 - diff1) +
    min(diff2, 10 - diff2) +
    min(diff3, 10 - diff3) +
    min(diff4, 10 - diff4)
  );
  return 0;
}
