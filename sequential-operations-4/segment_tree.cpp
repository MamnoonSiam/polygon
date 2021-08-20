#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
#define all(v) begin(v), end(v)
#define sz(v) (int)(v).size()
#define fi first
#define se second
#define rep(i,a,b) for(int i=a; i<b; ++i)

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

using complx = complex<mi>;

struct func {
  complx a, b;
  func() {}
  func(complx _a, complx _b) : a(_a), b(_b) {}
  func f(const func& o) const {
    return func(a * o.a, a * o.b + b);
  }
  complx f(complx z) {
    return z * a + b;
  }
};

template<class F>
struct Tree {
  typedef func T;
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
  freopen("in", "r", stdin);
#endif
  complx w(0, 1);
  int n, q;
  scanf("%d %d", &n, &q);
  Tree tr(n, [](func x, func y){ return y.f(x); }, func(complx(1,0), complx(0,0)));
  vector<int> x(n), y(n);
  vector<complx> v(n);
  vector<int> t(n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &x[i]);
  }
  for(int i = 0; i < n; ++i) {
    scanf("%d", &y[i]);
    v[i] = complx(x[i], y[i]);
  }
  for(int i = 0; i < n; ++i) {
    scanf("%d", &t[i]);
    tr.s[i + n] = func(pow(w, t[i]), v[i] - pow(w, t[i]) * v[i]);
  }
  for(int i = n-1; i >= 1; --i)
    tr.s[i] = tr.f(tr.s[i << 1], tr.s[i << 1 | 1]);
  while(q--) {
    int T; scanf("%d", &T);
    if(T == 1) {
      int i, xp, yp, tp;
      scanf("%d %d %d %d", &i, &xp, &yp, &tp);
      --i;
      v[i] = complx(xp, yp);
      t[i] = tp;
      tr.update(i, func(pow(w, t[i]), v[i] - pow(w, t[i]) * v[i]));
    } else {
      int l, r, xx, yy;
      scanf("%d %d %d %d", &l, &r, &xx, &yy);
      complx z = tr.query(l-1, r).f(complx(xx, yy));
      printf("%d %d\n", real(z).v, imag(z).v);
    }
  }
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/