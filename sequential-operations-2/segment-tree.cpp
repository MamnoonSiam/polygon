#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)
#define sz(v) (int)(v).size()
#define fi first
#define se second

const ll inf = 1e18;

struct base {
  ll a = 0, b = -inf, c = inf;
  base() {}
  base(ll _a, ll _b, ll _c) : a(_a), b(_b), c(_c) {
    b = max(b, -inf);
    c = min(c, inf);
  }
  ll f(ll x) {
    return min(c, max(b, x + a));
  }
};

base composition(base x, base y) {
  return base(
    x.a + y.a,
    max(y.b, min(x.c + y.a, x.b + y.a)),
    min(y.c, max(y.b, x.c + y.a))
  );
}

template<class F>
struct Tree {
  typedef base T;
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
#ifdef LOCAL
  freopen("01_sample.txt", "r", stdin);
#endif
  int n, q;
  scanf("%d %d", &n, &q);
  Tree tr(n, [](base a, base b){ return composition(a, b); }, base());
  while(q--) {
    int T; scanf("%d", &T);
    if(T == 1) { // update
      int i, a, b;
      scanf("%d %d %d", &i, &a, &b);
      base val;
      if(a == 1) {
        val = base(b, -inf, +inf);
      } else if(a == 2) {
        val = base(0, b, +inf);
      } else {
        val = base(0, -inf, b);
      }
      tr.update(i-1, val);
    } else {
      int l, r;
      ll x;
      scanf("%d %d %lld", &l, &r, &x);
      printf("%lld\n", tr.query(l-1, r).f(x));
    }
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/