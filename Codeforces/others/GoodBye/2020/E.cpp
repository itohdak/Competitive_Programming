#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

ll modpow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
}
void solve() {
  int n; cin >> n;
  vector<ll> X(n); rep(i, n) cin >> X[i];
  vector<vector<int>> cnt(60, vector<int>(2));
  vector<ll> pw(60);
  rep(i, 60) pw[i] = modpow(2, i);
  rep(i, 60) {
    rep(j, n) {
      cnt[i][(X[j]>>i)&1]++;
    }
    cnt[i][0] %= mod;
    cnt[i][1] %= mod;
  }
  ll ans = 0;
  rep(j, n) {
    ll sum1 = 0, sum2 = 0;
    rep(i, 60) {
      (sum1 += (((X[j]>>i)&1 ? cnt[i][1] : 0) * pw[i]) % mod) %= mod;
      (sum2 += (((X[j]>>i)&1 ? n : cnt[i][1]) * pw[i]) % mod) %= mod;
    }
    (ans += sum1 % mod * sum2 % mod) %= mod;
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
