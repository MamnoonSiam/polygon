#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)
#define sz(v) (int)(v).size()
#define fi first
#define se second
template<typename T>
inline void chkmin(T& x, T y) {
  x = x < y ? x : y;
}

const ll inf = 1e18;

tuple<ll,int,int> shortest_path(vector<pair<ii,ll>>& ls, int anot, int bnot) {
  // best path *---a--->--...-->---b---* in ls s.t. a != anot, b != bnot
  tuple<ll,int,int> opt{inf, -1, -1};
  for(auto [pa, w] : ls) {
    auto [s, t] = pa;
    if(s != anot and t != bnot) {
      opt = min(opt, make_tuple(w, s, t));
    }
  }
  return opt;
}

struct path {
  int s, t;
  ll w;
};

 
vector<path> get_top5(vector<pair<ii,ll>>& ls) {
  vector<path> ret;
  auto [w1, a1, b1] = shortest_path(ls, -1, -1);
  auto [w2, a2, b2] = shortest_path(ls, a1, -1);
  auto [w3, a3, b3] = shortest_path(ls, a1, b2);
  auto [w4, a4, b4] = shortest_path(ls, -1, b1);
  auto [w5, a5, b5] = shortest_path(ls, a4, b1);
  if(~a1) ret.push_back({a1, b1, w1});
  if(~a2) ret.push_back({a2, b2, w2});
  if(~a3) ret.push_back({a3, b3, w3});
  if(~a4) ret.push_back({a4, b4, w4});
  if(~a5) ret.push_back({a5, b5, w5});
  return ret;
}

vector<path> merge(vector<path> L, vector<path> R) {
  map<ii, ll> opt;
  for(path& l : L) {
    for(path& r : R) {
      if(l.t != r.s) {
        if(!opt.count(ii(l.s, r.t))) {
          opt[ii(l.s, r.t)] = l.w + r.w;
        } else {
          chkmin(opt[ii(l.s, r.t)], l.w + r.w);
        }
      }
    }
  }
  std::vector<path> ret;
  vector<pair<ii,ll>> ls(all(opt));
  return get_top5(ls);
}

template<class F>
struct Tree {
  typedef vector<path> T;
  vector<T> s;
  int m = 0;
  F f;
  T unit;
  Tree() {}
  Tree(int _n, F _f, T _unit = {}) : m(_n), f(_f), unit(_unit) {
    s.assign(2*m, unit);
  }
  void update(int pos, T val) {
    for(s[pos += m] = val; pos >>= 1;) // do u mean f= val?
      s[pos] = f(s[pos << 1], s[pos << 1 | 1]);
  }
  void preset(int i, T val) {
    s[i + m] = val;
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
  int n, q;
  scanf("%d %d", &n, &q);
  Tree tr(n-1, [](vector<path> x, vector<path> y){ return merge(x, y); });
  vector<vector<ii>> v(n-1);
  for(int i = 0; i < n-1; ++i) {
    int p; scanf("%d", &p);
    vector<pair<ii, ll>> me;
    v[i].resize(p);
    for(auto& [c, w] : v[i]) {
      scanf("%d %d", &c, &w);
      me.push_back({{c, c}, w});
    }
    vector<path> me_top5 = get_top5(me);
    tr.preset(i, me_top5);
  }
  tr.build();
  while(q--) {
    int T; scanf("%d", &T);
    if(T == 1) {
      int i, j;
      scanf("%d %d", &i, &j);
      --i, --j;
      scanf("%d %d", &v[i][j].fi, &v[i][j].se);
      vector<pair<ii, ll>> me;
      for(auto& [c, w] : v[i]) {
        me.push_back({{c, c}, w});
      }
      vector<path> me_top5 = get_top5(me);
      tr.update(i, me_top5);
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      --l, --r;
      auto res = tr.query(l, r);
      printf("%lld\n", sz(res) ? res[0].w : -1);
    }
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/