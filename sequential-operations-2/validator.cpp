#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define MAXN 200000
#define MAXQ 400000
#define LIM 1000000000

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
  for(int i = 0; i < q-1; ++i) {
    int T = inf.readInt(1, 2, "T");
    inf.readSpace();
    if(T == 1) { // update
      int i = inf.readInt(1, n, "i");
      inf.readSpace();
      int a = inf.readInt(1, 3, "a");
      inf.readSpace();
      int b = inf.readInt(-LIM, +LIM, "b");
    } else {
      int l = inf.readInt(1, n, "l");
      inf.readSpace();
      int r = inf.readInt(l, n, "r");
      inf.readSpace();
      int x = inf.readInt(-LIM, +LIM, "x");
    }
    inf.readEoln();
  }
  {
    int T = inf.readInt(2, 2, "T");
    inf.readSpace();
    int l = inf.readInt(1, n, "l");
    inf.readSpace();
    int r = inf.readInt(l, n, "r");
    inf.readSpace();
    int x = inf.readInt(-LIM, +LIM, "x");
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