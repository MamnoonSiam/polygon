#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)
#define sz(v) (int)(v).size()
#define fi first
#define se second

const int md = 1e9 + 7;

int add(int x, int y) {
  if((x += y) >= md) x -= md;
  return x;
}
int sub(int x, int y) {
  if((x -= y) < 0) x += md;
  return x;
}

struct pt {
  int x = 0, y = 0;
  pt() {}
  pt(int _x, int _y) : x(_x), y(_y) {}
  pt operator - (const pt& o) const {
    return pt(sub(x, o.x), sub(y, o.y));
  }
  pt operator + (const pt& o) const {
    return pt(add(x, o.x), add(y, o.y));
  }
};

void rotate90ccw(pt& p) {
  swap(p.x, p.y);
  // p.y = sub(0, p.y);
  p.x = sub(0, p.x);
}

void rotateccwwrt(pt p, pt& q, int t) {
  q = q - p;
  while(t--) rotate90ccw(q);
  q = q + p;
}

int main(int argc, char const *argv[])
{
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> x(n), y(n), t(n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &x[i]);
    x[i] = add(md, x[i]);
  }
  for(int i = 0; i < n; ++i) {
    scanf("%d", &y[i]);
    y[i] = add(y[i], md);
  }
  for(int i = 0; i < n; ++i) {
    scanf("%d", &t[i]);
  }
  while(q--) {
    int T; scanf("%d", &T);
    if(T == 1) {
      int i, xp, yp, tp;
      scanf("%d %d %d %d", &i, &xp, &yp, &tp);
      --i;
      x[i] = add(md, xp), y[i] = add(md, yp), t[i] = tp;
    } else {
      int l, r, xx, yy;
      scanf("%d %d %d %d", &l, &r, &xx, &yy);
      pt p(add(md, xx), add(md, yy));
      for(int i = l-1; i < r; ++i) {
        rotateccwwrt(pt(x[i], y[i]), p, t[i]);
      }
      printf("%d %d\n", p.x, p.y);
    }
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/