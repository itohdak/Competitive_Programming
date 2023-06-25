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
const ll mod = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return log10(A[i]) < log10(A[j]);
  });
  int d = 15;
  vector<ll> pw(2*d+1);
  pw[0] = 1;
  rep(i, 2*d+1) if(i) pw[i] = pw[i-1] * 10 % mod;
  ll ans = 0;
  vector<int> cnt(d+1);
  for(int i: id) {
    int rem = n;
    ll a = A[i];
    ll sum = 0;
    rep(j, log10(A[i])+1) {
      (sum += (a%10) * pw[2*j]) %= mod;
      a /= 10;
      (ans += (sum * 11 + a * pw[2*(j+1)] * 2) * cnt[j+1] % mod) %= mod;
      rem -= cnt[j+1];
    }
    (ans += (sum * 11) * rem % mod) %= mod;
    cnt[log10(A[i])+1]++;
  }
  cout << ans << endk;
  return 0;
}
