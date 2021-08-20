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

#define MAXN 200000
#define MAXQ 200000
#define LIM 1000000000

// ./generator [n] [q] [lim] [seed]
int main(int argc, char *argv[])
{
  registerGen(argc, argv, 1);
  int n = stoi(argv[1]);
  int q = stoi(argv[2]);
  int lim = stoi(argv[3]);

  assert(1 <= n and n <= MAXN);
  assert(1 <= q and q <= MAXQ);
  assert(1 <= lim and lim <= LIM);

  printf("%d %d\n", n, q);

  for(int i = 1; i <= n; ++i) {
    printf("%d%c", rnd.next(1, lim), " \n"[i==n]);
  }

  q--;
  while(q--) {
    int T = rnd.next(1, 2);
    if(T == 1) { // update
      int i = rnd.next(1, n);
      int x = rnd.next(1, lim);
      printf("%d %d %d\n", T, i, x);
    } else { // query
      int l, r;
      l = rnd.next(1, n);
      r = rnd.next(1, n);
      if(l > r) swap(l, r);
      printf("%d %d %d\n", T, l, r);
    }
  }
  {
    int l, r;
    l = rnd.next(1, n);
    r = rnd.next(1, n);
    if(l > r) swap(l, r);
    printf("%d %d %d\n", 2, l, r);
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/