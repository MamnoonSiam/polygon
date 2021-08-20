#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)
#define sz(v) (int)(v).size()
#define fi first
#define se second

/**
 * Description: modular arithmetic operations 
 * Source: Benq (https://codeforces.com/contest/1517/submission/114020736)
 */
 
template<int MOD, int RT> struct mint {
  static const int mod = MOD;
  static constexpr mint rt() { return RT; } // primitive root for FFT
  int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
  mint() { v = 0; }
  mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
    if (v < 0) v += MOD; }
  friend bool operator==(const mint& a, const mint& b) { 
    return a.v == b.v; }
  friend bool operator!=(const mint& a, const mint& b) { 
    return !(a == b); }
  friend bool operator<(const mint& a, const mint& b) { 
    return a.v < b.v; }
   
  mint& operator+=(const mint& m) { 
    if ((v += m.v) >= MOD) v -= MOD; 
    return *this; }
  mint& operator-=(const mint& m) { 
    if ((v -= m.v) < 0) v += MOD; 
    return *this; }
  mint& operator*=(const mint& m) { 
    v = int((ll)v*m.v%MOD); return *this; }
  mint& operator/=(const mint& m) { return (*this) *= inv(m); }
  friend mint pow(mint a, ll p) {
    mint ans = 1; assert(p >= 0);
    for (; p; p /= 2, a *= a) if (p&1) ans *= a;
    return ans; }
  friend mint inv(const mint& a) { assert(a.v != 0); 
    return pow(a,MOD-2); }
    
  mint operator-() const { return mint(-v); }
  mint& operator++() { return *this += 1; }
  mint& operator--() { return *this -= 1; }
  friend mint operator+(mint a, const mint& b) { return a += b; }
  friend mint operator-(mint a, const mint& b) { return a -= b; }
  friend mint operator*(mint a, const mint& b) { return a *= b; }
  friend mint operator/(mint a, const mint& b) { return a /= b; }
  friend ostream& operator << (ostream& out, const mint& a) {
    out << a.v; return out;
  }
};
const int md = 1e9 + 7; 
typedef mint<md,5> mi; // 5 is primitive root for both common mods

struct complx {
  mi a, b;
  complx(mi _a = mi(0), mi _b = mi(0)) : a(_a), b(_b) {}
  complx f(complx x) {
    return complx(a * x.a, a * x.b + b);
  }
  mi f(mi x) {
    return a * x + b;
  }
};

template<class F>
struct Tree {
  typedef complx T;
  vector<T> s;
  int n = 0;
  F f;
  T unit;
  Tree() {}
  Tree(int _n, F _f, T _unit) : n(_n), f(_f), unit(_unit) {
    s.assign(2*n, unit);
  }
  void update(int pos, T val) {
    for(s[pos += n] = val; pos >>= 1;) // do u mean f= val?
      s[pos] = f(s[pos << 1], s[pos << 1 | 1]);
  }
  T query(int b, int e) { // query [b, e)
    T ra = unit, rb = unit;
    for(b += n, e += n; b < e; b >>= 1, e >>= 1) {
      if(b & 1) ra = f(ra, s[b++]);
      if(e & 1) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

int main(int argc, char const *argv[])
{
#ifdef LOCAL
  freopen("test", "r", stdin);
#endif
  int n, q;
  scanf("%d %d", &n, &q);
  Tree tr(n, [](complx a, complx b){ return b.f(a); }, complx(mi(1), mi(0)));
  while(q--) {
    int T; scanf("%d", &T);
    if(T == 1) { // update
      int i, a, b;
      scanf("%d %d %d", &i, &a, &b);
      complx val;
      if(a == 1) {
        val = complx(mi(1), mi(b));
      } else if(a == 2) {
        val = complx(mi(1), mi(-b));
      } else if(a == 3) {
        val = complx(mi(b), mi(0));
      } else {
        val = complx(inv(mi(b)), mi(0));
      }
      tr.update(i-1, val);
    } else {
      int l, r, x;
      scanf("%d %d %d", &l, &r, &x);
      mi xp = tr.query(l-1, r).f(mi(x));
      printf("%d\n", xp.v);
    }
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/