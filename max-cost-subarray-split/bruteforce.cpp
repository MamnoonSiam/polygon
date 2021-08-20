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

ll solve(vi a) {
  int n = sz(a);
  vector<ll> dp(n+1, -inf);
  dp[0] = 0;
  for(int i = 1; i <= n; ++i) {
    int mn = INT_MAX, mx = INT_MIN;
    for(int j = i; j >= 1; --j) {
      mn = min(mn, a[j-1]);
      mx = max(mx, a[j-1]);
      dp[i] = max(dp[i], dp[j-1] + mx - mn);
    }
  }
  return dp.back();
}

int main(int argc, char const *argv[])
{
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  int n, q;
  scanf("%d %d", &n, &q);
  vi a(n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  while(q--) {
    int T; scanf("%d", &T);
    if(T == 1) {
      int i, x;
      scanf("%d %d", &i, &x);
      a[i-1] = x;
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%lld\n", solve(vi(a.begin()+l-1, a.begin()+r)));
    }
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/