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
#define LIM 100000000
#define MAXK 5

// ./generator [n] [k] [q] [llim] [rlim] [seed]
int main(int argc, char *argv[])
{
  registerGen(argc, argv, 1);
  int n = stoi(argv[1]);
  int k = stoi(argv[2]);
  int q = stoi(argv[3]);
  int llim = stoi(argv[4]);
  int rlim = stoi(argv[5]);

  assert(1 <= n and n <= MAXN);
  assert(1 <= q and q <= MAXQ);
  assert(1 <= k and k <= n and k <= MAXK);
  assert(-LIM <= llim and llim <= rlim and rlim <= LIM);

  printf("%d %d %d\n", n, k, q);

  for(int i = 1; i <= k; ++i) {
    printf("%d%c", rnd.next(llim, rlim), " \n"[i==k]);
  }

  for(int i = 1; i <= n; ++i) {
    printf("%d%c", rnd.next(llim, rlim), " \n"[i==n]);
  }

  q--;
  while(q--) {
    int T = rnd.next(1, 2);
    if(T == 1) { // update
      int i = rnd.next(1, n);
      int x = rnd.next(llim, rlim);
      printf("%d %d %d\n", T, i, x);
    } else { // query
      int l, r;
      do {
        l = rnd.next(1, n);
        r = rnd.next(1, n);
        if(l > r) swap(l, r);
      } while(r - l + 1 < k);
      printf("%d %d %d\n", T, l, r);
    }
  }
  {
    int l, r;
    do {
      l = rnd.next(1, n);
      r = rnd.next(1, n);
      if(l > r) swap(l, r);
    } while(r - l + 1 < k);
    printf("%d %d %d\n", 2, l, r);
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/