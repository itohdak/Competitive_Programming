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
  int n, m, k; cin >> n >> m >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<pair<int, int>> P(m); rep(i, m) cin >> P[i].first >> P[i].second;
  map<int, vector<int>> mp;
  rep(i, m) {
    mp[P[i].first-P[i].second].push_back(P[i].second);
  }
  for(auto& ele: mp) sort(all(ele.second));
  sort(all(A));
  A.erase(begin(A)+k, end(A));
  reverse(all(A));
  vector<vector<ll>> dp(k+1, vector<ll>(k+1, longinf)); // 今何個目を見ていてそれまでに何個買ったか
  dp[0][0] = 0;
  rep(i, k) {
    rep(j, k+1) {
      chmin(dp[i+1][j+1], dp[i][j]+A[i]); // 割引を使わない
      if(mp.count(j)) {
        // int rem = k-i;
        // auto itr = upper_bound(all(mp[j]), rem);
        // if(itr == mp[j].begin()) continue;
        // itr--;
        // chmin(dp[i+*itr][0], dp[i][j]);
        for(auto ele: mp[j]) {
          if(i+ele < k+1) chmin(dp[i+ele][0], dp[i][j]);
        }
      }
    }
  }
  cout << *min_element(all(dp[k])) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
