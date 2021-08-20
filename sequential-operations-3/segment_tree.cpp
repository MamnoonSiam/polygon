#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)
#define sz(v) (int)(v).size()
#define fi first
#define se second

struct info {
  ll xsum = 0, ysum = 0, tot = 0;
  info() {}
  info(ll _xsum, ll _ysum, ll _tot = 0) {
    xsum = _xsum;
    ysum = _ysum;
    tot = _tot;
  }
  info operator + (const info& o) const {
    return info(xsum + o.xsum, ysum + o.ysum, tot + o.tot + xsum * o.ysum);
  }
};

template<class F>
struct Tree {
  typedef info T;
  vector<T> s;
  int n = 0;
  F f;
  T unit;
  Tree() {}
  Tree(int _n, F _f, T _unit) : n(_n), f(_f), unit(_unit) {
    s.assign(2*n, unit);
  }
  void update(int pos, T val) {
    for(s[pos += n] = val; pos >>= 1;) // do u mean f= val?
      s[pos] = f(s[pos << 1], s[pos << 1 | 1]);
  }
  T query(int b, int e) { // query [b, e)
    T ra = unit, rb = unit;
    for(b += n, e += n; b < e; b >>= 1, e >>= 1) {
      if(b & 1) ra = f(ra, s[b++]);
      if(e & 1) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

int main(int argc, char const *argv[])
{
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> a(n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  Tree tr(n, [](info x, info y){ return x + y; }, info());
  for(int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if(a[i] == 1) {
      tr.update(i, info(x, 0));
    } else {
      tr.update(i, info(0, x));
    }
  }
  while(q--) {
    int T; scanf("%d", &T);
    if(T == 1) { // update
      int i, ap, bp;
      scanf("%d %d %d", &i, &ap, &bp);
      if(ap == 1) {
        tr.update(i-1, info(bp, 0));
      } else {
        tr.update(i-1, info(0, bp));
      }
    } else { // query
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%lld\n", tr.query(l-1, r).tot);
    }
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/