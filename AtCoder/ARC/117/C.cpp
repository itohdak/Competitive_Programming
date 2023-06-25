#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
// const ll mod = 1e9+7;
const ll mod = 3;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

ll modinv(ll a, ll m=mod) {
  ll b = m, u = 1, v = 0;
  while(b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if(u < 0) u += m;
  return u;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  vector<int> A(n);
  rep(i, n) {
    if(s[i] == 'B') {
      A[i] = 0;
    } else if(s[i] == 'W') {
      A[i] = 1;
    } else {
      A[i] = 2;
    }
  }
  if(n % 2 == 0) {
    vector<int> next(n-1);
    rep(i, n-1) {
      next[i] = (mod - (A[i] + A[i+1]) % mod) % mod;
    }
    A = next;
    n--;
  }
  int ans = 0;
  vector<int> comb(n);
  {
    comb[0] = 1;
    int denom = 1, numer = 1; // 分母、分子
    int cnt = 0;
    for(int i=1; i<=n-1; i++) {
      int tmp_n = n-i;
      while(tmp_n % 3 == 0) {
        tmp_n /= 3;
        cnt++;
      }
      int tmp_d = i;
      while(tmp_d % 3 == 0) {
        tmp_d /= 3;
        cnt--;
      }
      (numer *= tmp_n) %= mod;
      (denom *= tmp_d) %= mod;
      if(cnt) {
        comb[i] = 0;
      } else {
        comb[i] = numer * modinv(denom) % mod;
      }
    }
  }
  rep(i, n) {
    (ans += A[i] * comb[i]) %= mod;
  }
  if(ans == 0) {
    cout << 'B' << endk;
  } else if(ans == 1) {
    cout << 'W' << endk;
  } else {
    cout << 'R' << endk;
  }
  return 0;
}
