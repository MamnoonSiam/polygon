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

int k = 10;
array<mi, 10> mul(array<mi, 10> x, array<mi, 10> y) {
  array<mi, 20> z;
  for(int i = 0; i < k; ++i) {
    for(int j = 0; j < k; ++j) {
      z[i+j] += x[i] * y[j];
    }
  }
  array<mi, 10> zz;
  for(int i = 0; i < k; ++i) {
    zz[i] = z[i] + z[i+k];
  }
  return zz;
}

int main(int argc, char const *argv[])
{
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  array<mi, 10> x, y;
  for(int i = 0; i < 10; ++i) {
    x[i] = mi(rand());
    y[i] = mi(rand());
  }
  mi tot;
  for(int i = 0; i < 2 * 17 * 100000; ++i) {
    array<mi, 10> z = mul(x, y);
    tot += z[5];
  }
  cout << tot.v << endl;
  return 0;
}
/*
* use std::array instead of std::vector, if u can
* overflow?
* array bounds
*/