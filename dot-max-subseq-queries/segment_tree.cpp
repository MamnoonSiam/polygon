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
using mat = array<array<ll, 5>, 5>;

int k;

mat mul(mat x, mat y) {
  mat z;
  for(int i = 0; i < k; ++i) {
    for(int j = 0; j < k; ++j) {
      ll& zz = z[i][j] = max(x[i][j], y[i][j]);
      for(int l = i; l < j; ++l) {
        zz = max(zz, x[i][l] + y[l+1][j]);
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
  int n, q;
  scanf("%d %d %d", &n, &k, &q);
  vector<ll> b(k), a(n);
  for(int i = 0; i < k; ++i) {
    scanf("%lld", &b[i]);
  }
  mat mat_inf;
  for(int i = 0; i < k; ++i)
    for(int j = 0; j < k; ++j)
      mat_inf[i][j] = -inf;
  Tree tr(n, [](mat x, mat y){ return mul(x, y); }, mat_inf);
  for(int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    mat me = mat_inf;
    for(int j = 0; j < k; ++j) {
      me[j][j] = a[i] * b[j];
    }
    tr.s[n + i] = me;
  }
  for(int i = n-1; i >= 1; --i)
    tr.s[i] = mul(tr.s[i << 1], tr.s[i << 1 | 1]);
  while(q--) {
    int T; scanf("%d", &T);
    if(T == 1) {
      int i, x;
      scanf("%d %d", &i, &x);
      --i;
      a[i] = x;
      mat me = mat_inf;
      for(int j = 0; j < k; ++j) {
        me[j][j] = a[i] * b[j];
      }
      tr.update(i, me);
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      --l, --r;
      printf("%lld\n", tr.query(l, r+1)[0][k-1]);
    }
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/