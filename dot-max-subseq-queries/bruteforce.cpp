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

ll solve(vector<ll> a, vector<ll> b) {
  vector<vector<ll>> dp(sz(b)+1, vector<ll>(sz(a)+1, -inf));
  dp[0] = vector<ll>(sz(a)+1, 0);
  for(int i = 1; i <= sz(b); ++i) {
    for(int j = 1; j <= sz(a); ++j) {
      dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + b[i-1] * a[j-1]);
    }
  }
  return dp.back().back();
}

int main(int argc, char const *argv[])
{
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  int n, k, q;
  scanf("%d %d %d", &n, &k, &q);
  vector<ll> b(k), a(n);
  for(int i = 0; i < k; ++i) {
    scanf("%lld", &b[i]);
  }
  for(int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
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
      --l, --r;
      printf("%lld\n", solve(vector<ll>(a.begin()+l, a.begin()+r+1), b));
    }
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/