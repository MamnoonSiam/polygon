#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000
#define MAXQ 200000

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)
#define sz(v) (int)(v).size()
#define fi first
#define se second

const int m = 1e9 + 7;

// ./generator [seed] [n] [q] [lim]
// lim >= 1
// n >= 1, q >= 1
int main(int argc, char *argv[])
{
  registerGen(argc, argv, 1);

  int n = stoi(argv[2]);
  int q = stoi(argv[3]);
  int lim = stoi(argv[4]);

  printf("%d %d\n", n, q);
  for(int i = 1; i < q; ++i) {
    int T = rnd.next(1, 2);
    if(T == 1) { // update
      int idx = rnd.next(1, n);
      int a = rnd.next(1, 4);
      int b = rnd.next(0 + int(a == 4), lim);
      printf("%d %d %d %d\n", T, idx, a, b);
    } else {
      int l = rnd.next(1, n);
      int r = rnd.next(1, n);
      if(l > r) swap(l, r);
      int x = rnd.next(0, lim);
      printf("%d %d %d %d\n", T, l, r, x);
    }
  }
  {
    int l = rnd.next(1, n);
    int r = rnd.next(1, n);
    if(l > r) swap(l, r);
    int x = rnd.next(0, lim);
    printf("%d %d %d %d\n", 2, l, r, x);
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/