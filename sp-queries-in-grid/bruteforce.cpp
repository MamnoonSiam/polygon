#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)
#define sz(v) (int)(v).size()
#define fi first
#define se second

const int inf = 1e9 + 420;
inline int add(int x, int y) {
  return x == inf or y == inf ? inf : x + y;
}

int main(int argc, char const *argv[])
{
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  vector<vi> a(n, vi(m));
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  while(q--) {
    int T; scanf("%d", &T);
    if(T == 1) {// update
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      a[x-1][y-1] = z;
    } else {
      vector<vi> dp(n, vi(m, inf));
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      --x1, --x2, --y1, --y2;
      dp[x2][y2] = a[x2][y2];
      for(int j = m-2; j >= 0; --j) {
        for(int i = 0; i < n; ++i) {
          for(int ip : {i-1, i, i+1}) if(ip >= 0 and ip < n) {
            dp[i][j] = min(dp[i][j], add(dp[ip][j+1], a[i][j]));
          }
        }
      }
      /*for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
          cerr << dp[i][j] << ' ';
        } cerr << endl;
      }*/
      printf("%d\n", dp[x1][y1]);
    }
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/