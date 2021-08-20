#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)
#define sz(v) (int)(v).size()
#define fi first
#define se second

/*
0         1       2
(-)open   close   (+)open
compatability:
  mate(x) = (x+1)^3
*/

const ll inf = 1e18;
using mat = array<array<ll, 3>, 3>;

mat mul(mat x, mat y) {
  mat z;
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      ll& zz = z[i][j] = max(x[i][j], y[i][j]);
      for(int k = 0; k < 3; ++k) {
        zz = max(zz, x[i][k] + y[(k+1)^3][j]);
      }
    }
  }
  return z;
}

template<class F>
struct Tree {
  typedef mat T;
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
  freopen("in", "r", stdin);
#endif
  mat mat_id;
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j)
      mat_id[i][j] = -inf;
  mat_id[1][1] = 0;

  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> a(n);
  Tree tr(n, [](mat x, mat y){ return mul(x, y); }, mat_id);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    mat me = mat_id;
    for(int x = 0; x < 3; ++x)
      for(int y = 0; y < 3; ++y)
        if(x == 1 or y == 1)
          me[x][y] = (x+y-2) * a[i];
    tr.s[n + i] = me;
  }
  for(int i = n-1; i >= 1; --i) {
    tr.s[i] = mul(tr.s[i << 1], tr.s[i << 1 | 1]);
  }
  while(q--) {
    int T; scanf("%d", &T);
    if(T == 1) {
      int i, _x;
      scanf("%d %d", &i, &_x);
      a[i-1] = _x;
      mat me = mat_id;
      for(int x = 0; x < 3; ++x)
        for(int y = 0; y < 3; ++y)
          if(x == 1 or y == 1)
            me[x][y] = (x+y-2) * a[i-1];
      tr.update(i-1, me);
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%lld\n", tr.query(l-1, r)[1][1]);
    }
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/