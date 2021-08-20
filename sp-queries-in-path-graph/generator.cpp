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
#define MAXQ 100000
#define WLIM 1000000000
#define PLIM 50

// ./generator [n] [q] [plim] [clim] [wlim] [seed]
int main(int argc, char *argv[])
{
  registerGen(argc, argv, 1);
  int n = stoi(argv[1]);
  int q = stoi(argv[2]);
  int plim = stoi(argv[3]);
  int clim = stoi(argv[4]);
  int wlim = stoi(argv[5]);

  assert(2 <= n and n <= MAXN);
  assert(1 <= q and q <= MAXQ);
  assert(1 <= plim and plim <= PLIM);
  assert(1 <= clim and clim <= n);
  assert(1 <= wlim and wlim <= WLIM);

  printf("%d %d\n", n, q);

  vector<int> p(n);

  for(int i = 1; i < n; ++i) {
    p[i-1] = rnd.next(1, plim);
    printf("%d\n", p[i-1]);
    for(int j = 1; j <= p[i-1]; ++j) {
      printf("%d %d\n", rnd.next(1, clim), rnd.next(1, wlim));
    }
  }

  q--;
  while(q--) {
    int T = rnd.next(1, 2);
    if(T == 1) {
      int i = rnd.next(1, n-1);
      int j = rnd.next(1, p[i-1]);
      int cp = rnd.next(1, clim);
      int wp = rnd.next(1, wlim);
      printf("%d %d %d %d %d\n", T, i, j, cp, wp);
    } else {
      int u, v;
      do {
        u = rnd.next(1, n);
        v = rnd.next(1, n);
        if(u > v) swap(u, v);
      } while(u == v);
      printf("%d %d %d\n", T, u, v);
    }
  }
  {
    int u, v;
    do {
      u = rnd.next(1, n);
      v = rnd.next(1, n);
      if(u > v) swap(u, v);
    } while(u == v);
    printf("%d %d %d\n", 2, u, v);
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/