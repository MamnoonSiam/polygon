#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define MAXN 5
#define MAXM 100000
#define MAXQ 50000
#define LIM 10000

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
  int m = inf.readInt(1, MAXM, "m");
  inf.readSpace();
  int q = inf.readInt(1, MAXQ, "q");
  inf.readEoln();
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      int x = inf.readInt(-LIM, LIM, "cell");
      if(j < m) inf.readSpace();
    }
    inf.readEoln();
  }
  for(int i = 0; i < q-1; ++i) {
    int T = inf.readInt(1, 2, "T");
    inf.readSpace();
    if(T == 1) { // update
      int i = inf.readInt(1, n, "x");
      inf.readSpace();
      int a = inf.readInt(1, m, "y");
      inf.readSpace();
      int b = inf.readInt(-LIM, +LIM, "z");
    } else {
      int x1 = inf.readInt(1, n, "x1");
      inf.readSpace();
      int y1 = inf.readInt(1, m, "y1");
      inf.readSpace();
      int x2 = inf.readInt(1, n, "x2");
      inf.readSpace();
      int y2 = inf.readInt(1, m, "y2");
    }
    inf.readEoln();
  }
  {
    int T = inf.readInt(2, 2, "T");
    inf.readSpace();
    int x1 = inf.readInt(1, n, "x1");
    inf.readSpace();
    int y1 = inf.readInt(1, m, "y1");
    inf.readSpace();
    int x2 = inf.readInt(1, n, "x2");
    inf.readSpace();
    int y2 = inf.readInt(1, m, "y2");
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