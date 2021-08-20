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


// input_translator.cpp [seed] < inp.txt
int main(int argc, char *argv[])
{
  registerGen(argc, argv, 1);
  int n, q;
  scanf("%d", &n);
  vector<tuple<int, int, int, int>> allq;
  for(int i = 1; i <= n; ++i) {
    int a, t;
    scanf("%d %d", &a, &t);
    allq.emplace_back(1, i, t, a);
  }
  scanf("%d", &q);
  for(int i = 1; i <= q; ++i) {
    int l = rnd.next(1, n);
    int r = rnd.next(1, n);
    if(l > r) swap(l, r);
    int x;
    scanf("%d", &x);
    allq.emplace_back(2, l, r, x);
  }
  shuffle(allq.begin(), allq.end()-1);
  printf("%d %d\n", n, n+q);
  for(auto [T, a, b, c] : allq) {
    printf("%d %d %d %d\n", T, a, b, c);
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/