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


// ./generator [n] [q] [lim] [seed]
int main(int argc, char *argv[])
{
  registerGen(argc, argv, 1);
  int n = stoi(argv[1]);
  int q = stoi(argv[2]);
  int lim = stoi(argv[3]);
  printf("%d %d\n", n, q);
  for(int i = 1; i <= n; ++i) {
    printf("%d%c", rnd.next(1, 2), " \n"[i==n]);
  }
  for(int i = 1; i <= n; ++i) {
    printf("%d%c", rnd.next(-lim, lim), " \n"[i==n]);
  }
  assert(q >= 1);
  q--;
  while(q--) {
    int T = rnd.next(1, 2);
    if(T == 1) { // update
      int i = rnd.next(1, n);
      int ap = rnd.next(1, 2);
      int bp = rnd.next(-lim, lim);
      printf("%d %d %d %d\n", T, i, ap, bp);
    } else { // query
      int l = rnd.next(1, n);
      int r = rnd.next(1, n);
      if(l > r) swap(l, r);
      printf("%d %d %d\n", T, l, r);
    }
  }
  {
    int l = rnd.next(1, n);
    int r = rnd.next(1, n);
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