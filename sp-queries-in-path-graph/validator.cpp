#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define MAXN 100000
#define MAXQ 100000
#define WLIM 1000000000
#define PLIM 50

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)
#define sz(v) (int)(v).size()
#define fi first
#define se second

int main(int argc, char *argv[])
{
  registerValidation(argc, argv);

  int n = inf.readInt(1, MAXN, "n");
  inf.readSpace();
  int q = inf.readInt(1, MAXQ, "q");
  inf.readEoln();
  vector<int> p(n);
  for(int i = 1; i < n; ++i) {
    p[i-1] = inf.readInt(1, PLIM, "p_i");
    inf.readEoln();
    for(int j = 1; j <= p[i-1]; ++j) {
      inf.readInt(1, n, "c_ij");
      inf.readSpace();
      inf.readInt(1, WLIM, "w_ij");
      inf.readEoln();
    }
  }
  q--;
  while(q--) {
    int T = inf.readInt(1, 2, "T");
    inf.readSpace();
    if(T == 1) {
      int i = inf.readInt(1, n-1, "i");
      inf.readSpace();
      int j = inf.readInt(1, p[i-1], "j");
      inf.readSpace();
      int cp = inf.readInt(1, n, "cp");
      inf.readSpace();
      int wp = inf.readInt(1, WLIM, "wp");
    } else {
      int u = inf.readInt(1, n-1, "u");
      inf.readSpace();
      int v = inf.readInt(u+1, n, "v");
    }
    inf.readEoln();
  }
  {
    int T = inf.readInt(2, 2, "T");
    inf.readSpace();
    int u = inf.readInt(1, n-1, "u");
    inf.readSpace();
    int v = inf.readInt(u+1, n, "v");
    inf.readEoln();
  }
  inf.readEof();
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/