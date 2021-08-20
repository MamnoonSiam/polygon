#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)
#define sz(v) (int)(v).size()
#define fi first
#define se second
using mat = array<array<int, 5>, 5>;
const int inf = 1e9 + 420;
inline int add(int x, int y) {
  return x == inf or y == inf ? inf : x + y;
}

int n;

mat mul(mat x, mat y) {
  mat z;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      int& zz = z[i][j] = inf;
      for(int k = 0; k < n; ++k) {
        for(int kk : {k-1, k, k+1}) if(kk >= 0 and kk < n) {
          zz = min(zz, add(x[i][k], y[kk][j]));
        }
      }
    }
  }
  return z;
}

template<class F>
struct Tree {
  typedef mat T;
  vector<T> s;
  int m = 0;
  F f;
  T unit;
  Tree() {}
  Tree(int _n, F _f, T _unit) : m(_n), f(_f), unit(_unit) {
    s.assign(2*m, unit);
  }
  void update(int pos, T val) {
    for(s[pos += m] = val; pos >>= 1;) // do u mean f= val?
      s[pos] = f(s[pos << 1], s[pos << 1 | 1]);
  }
  void build() {
    for(int i = m-1; i >= 1; --i)
      s[i] = f(s[i << 1], s[i << 1 | 1]);
  }
  T query(int b, int e) { // query [b, e)
    T ra = unit, rb = unit;
    bool lef = 0, rig = 0;
    for(b += m, e += m; b < e; b >>= 1, e >>= 1) {
      if(b & 1) {
        if(!lef) {
          ra = s[b++];
          lef = 1;
        } else {
          ra = f(ra, s[b++]);
        }
      }
      if(e & 1) {
        if(!rig) {
          rb = s[--e];
          rig = 1;
        } else {
          rb = f(s[--e], rb);
        }
      }
    }
    return lef and rig ? f(ra, rb) : (lef ? ra : rb);
  }
};

int main(int argc, char const *argv[])
{
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  int m, q;
  scanf("%d %d %d", &n, &m, &q);
  mat mat_inf;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      mat_inf[i][j] = inf;
  Tree tr(m, [](mat x, mat y){ return mul(x, y); }, mat());
  vector<vi> a(n, vi(m));
  for(int i = 0; i < n; ++i) {
    for(int j = 0 ; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for(int j = 0; j < m; ++j) {
    mat me = mat_inf;
    for(int i = 0; i < n; ++i) {
      me[i][i] = a[i][j];
    }
    tr.s[j + m] = me;
  }
  tr.build();
  while(q--) {
    int T; scanf("%d", &T);
    if(T == 1) { // update 
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      a[x-1][y-1] = z;
      mat me = mat_inf;
      for(int i = 0; i < n; ++i) {
        me[i][i] = a[i][y-1];
      }
      tr.update(y-1, me);
    } else { // query
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      x1--, x2--, y2--, y1--;
      printf("%d\n", y1 <= y2 ? tr.query(y1, y2+1)[x1][x2] : inf);
    }
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/