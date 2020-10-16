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
  int a, n, m; cin >> a >> n >> m;
  vector<pair<int, int>> P(n), U(m);
  rep(i, n) cin >> P[i].first >> P[i].second;
  sort(all(P));
  rep(i, m) cin >> U[i].first >> U[i].second;
  sort(all(U));
  vector<vector<ll>> dp(a+1, vector<ll>(m+1, longinf));
  dp[0][m] = 0;
  int k = 0;
  int l = 0;
  rep(i, a) {
    if(k < n && P[k].second <= i) k++;
    rep(j, m+1) {
      // 何もしない
      if(j != m) chmin(dp[i+1][j], dp[i][j]+U[j].second);
      else if(k >= n || !(P[k].first <= i && i <= P[k].second)) chmin(dp[i+1][j], dp[i][j]);
      // 傘を持つ／持ち替える
      REP(a, l, m) {
        if(i != U[a].first) break;
        chmin(dp[i+1][a], dp[i][j]+U[a].second);
      }
      if(k >= n || !(P[k].first <= i && i <= P[k].second)) chmin(dp[i+1][m], dp[i][j]);
    }
    while(l < m && i == U[l].first) l++;
  }
  ll mn = *min_element(all(dp[a]));
  cout << (mn==longinf ? -1 : mn) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
