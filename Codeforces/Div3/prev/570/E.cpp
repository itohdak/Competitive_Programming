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

void solve() {
  int n; ll k; cin >> n >> k;
  string s; cin >> s;
  vector<int> last(26, -1);
  // dp[i+1][n]: i番目の文字を選び、長さがnの部分文字列の総数
  vector<vector<ll>> dp(n+1, vector<ll>(105));
  dp[0][0] = 1;
  rep(i, n) {
    int id = s[i]-'a';
    rep(k, 101) {
      REP(j, last[id]+1, i+1) { // select
        dp[i+1][k+1] += dp[j][k];
        chmin(dp[i+1][k+1], 1e12);
      }
    }
    last[id] = i;
  }
  vector<ll> cnt(105);
  rep(i, 101) {
    rep(j, n+1) {
      cnt[i] += dp[j][i];
      chmin(cnt[i], 1e12);
    }
  }
  ll ans = 0;
  ll rem = k;
  rrep(i, 101) {
    if(cnt[i] >= rem) {
      ans += rem * (n-i);
      rem = 0;
      break;
    } else {
      ans += cnt[i] * (n-i);
      rem -= cnt[i];
    }
  }
  // cout << cnt << endk;
  if(rem) {
    cout << -1 << endk;
  } else {
    cout << ans << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
