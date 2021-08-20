#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)
#define sz(v) (int)(v).size()
#define fi first
#define se second

#define MAXN 100000
#define MAXQ 50000
#define LIM 10000

// ./generator [n] [m] [q] [llim] [rlim] [seed]
int main(int argc, char *argv[])
{
  registerGen(argc, argv, 1);
  int n = stoi(argv[1]);
  int m = stoi(argv[2]);
  int q = stoi(argv[3]);
  int llim = stoi(argv[4]);
  int rlim = stoi(argv[5]);
  printf("%d %d %d\n", n, m, q);
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      printf("%d%c", rnd.next(llim, rlim), " \n"[j==m]);
    }
  }
  q--;
  while(q--) {
    int T = rnd.next(1, 2);
    if(T == 1) { // update
      int x = rnd.next(1, n);
      int y = rnd.next(1, m);
      int z = rnd.next(llim, rlim);
      printf("%d %d %d %d\n", T, x, y, z);
    } else { // query
      int x1 = rnd.next(1, n);
      int y1 = rnd.next(1, m);
      int x2 = rnd.next(1, n);
      int y2 = rnd.next(1, m);
      printf("%d %d %d %d %d\n", T, x1, y1, x2, y2);
    }
  }
  {
    int x1 = rnd.next(1, n);
    int y1 = rnd.next(1, m);
    int x2 = rnd.next(1, n);
    int y2 = rnd.next(1, m);
    printf("%d %d %d %d %d\n", 2, x1, y1, x2, y2);
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/