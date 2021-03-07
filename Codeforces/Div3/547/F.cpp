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
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> sum(n+1); rep(i, n) sum[i+1] = sum[i] + A[i];
  map<ll, vector<pair<int, int>>> mp;
  rep(i, n) REP(j, i, n) {
    mp[sum[j+1]-sum[i]].push_back({i, j});
  }
  vector<pair<int, int>> ans;
  for(auto& ele: mp) {
    auto v = ele.second;
    int m = v.size();
    vector<int> dp(m, 1);
    vector<int> par(m, -1);
    rep(i, m) {
      if(i+1 < m && dp[i+1] < dp[i]) {
        dp[i+1] = dp[i];
        par[i+1] = par[i];
      }
      int lb = lower_bound(all(v), make_pair(v[i].second+1, 0)) - begin(v);
      if(lb == m) continue;
      if(dp[lb] < dp[i]+1) {
        dp[lb] = dp[i]+1;
        par[lb] = i;
      }
    }
    int mxi = max_element(all(dp)) - begin(dp);
    int mx = dp[mxi];
    if(ans.size() < mx) {
      // cout << ele.first << endk;
      // cout << v << endk;
      // cout << dp << endk;
      // cout << par << endk;
      ans.clear();
      int tmp = mxi;
      while(tmp != -1) {
        ans.push_back(v[tmp]);
        tmp = par[tmp];
      }
    }
  }
  cout << ans.size() << endk;
  for(auto ele: ans) cout << ele.first+1 << ' ' << ele.second+1 << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
