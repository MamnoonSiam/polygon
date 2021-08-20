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
const int inf = 1e9 + 9;

int n = 5;

inline int add(int x, int y) {
  return x == inf or y == inf ? inf : x + y;
}

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

int main(int argc, char const *argv[])
{
  mt19937 rng(69);
  auto random = [&rng](int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
  };
  mat x, y;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      x[i][j] = random(-10000000, 10000000);
      y[i][j] = random(-10000000, 10000000);
    }
  }
  ll sum = 0;
  int q = 50000;
  int lg = 17;
  for(int _ = 0; _ < q; ++_) {
    for(int __ = 0; __ < 2*lg; ++__) {
      mat z = mul(x, y);
      sum += z[0][0];
    }
  }
  cout << sum << endl;
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/