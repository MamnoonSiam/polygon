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

ll solve(vector<vector<ii>> v) {
  int n = sz(v);
  map<ii, ll> dp;
  function<ll(int,int)> f = [&](int pc, int u) {
    if(dp.count(ii(pc, u))) return dp[ii(pc, u)];
    if(u == n) return dp[ii(pc, u)] = 0;
    ll& ret = dp[ii(pc, u)] = inf;
    for(auto [c, w] : v[u]) {
      if(c != pc) {
        ret = min(ret, f(c, u+1) + w);
      }
    }
    return ret;
  };
  return f(0, 0);
}

int main(int argc, char const *argv[])
{
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  int n, q;
  scanf("%d %d", &n, &q);
  vector<vector<ii>> v(n);
  for(int i = 1; i < n; ++i) {
    int p; scanf("%d", &p);
    v[i].resize(p);
    for(auto& [c, w] : v[i]) {
      scanf("%d %d", &c, &w);
    }
  }
  while(q--) {
    int T; scanf("%d", &T);
    if(T == 1) {
      int i, j;
      scanf("%d %d", &i, &j);
      scanf("%d %d", &v[i][j-1].fi, &v[i][j-1].se);
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      ll ans = solve(vector<vector<ii>>(v.begin()+l, v.begin()+r));
      printf("%lld\n", ans == inf ? -1 : ans);
    }
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/