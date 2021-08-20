#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)
#define sz(v) (int)(v).size()
#define fi first
#define se second

int main(int argc, char const *argv[])
{
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> a(n);
  vector<int> b(n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  while(q--) {
    int T; scanf("%d", &T);
    if(T == 1) { // update
      int i, ap, bp;
      scanf("%d %d %d", &i, &ap, &bp);
      a[i-1] = ap, b[i-1] = bp;
    } else { // query
      int l, r;
      scanf("%d %d", &l, &r);
      ll x = 0, y = 0;
      for(int i = l-1; i < r; ++i) {
        if(a[i] == 1) {
          x += b[i];
        } else {
          y += x * b[i];
        }
      }
      printf("%lld\n", y);
    }
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/