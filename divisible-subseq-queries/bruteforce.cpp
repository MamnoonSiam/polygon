#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)
#define sz(v) (int)(v).size()
#define fi first
#define se second

int k;
int solve(vi a) {
  int n = sz(a);
  int ret = 0;
  for(int msk = 0; msk < (1 << n); ++msk) {
    int sum = 0;
    for(int i = 0; i < n; ++i) {
      if(msk >> i & 1) {
        sum += a[i];
      }
    }
    if(sum % k == 0 ){
      ret ++;
    }
  }
  return ret;
}

int main(int argc, char const *argv[])
{
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  int n, q;
  scanf("%d %d %d", &n, &k, &q);
  assert(n <= 15);
  vector<int> a(n);
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
      --l, --r;
      printf("%d\n", solve(vi(a.begin()+l, a.begin()+r+1)));
    }
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/