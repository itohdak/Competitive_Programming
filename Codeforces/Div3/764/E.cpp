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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

// {'{t{12340219}', '20215601', '56782022', '12300678'}: typo
void solve() {
  int n, m; cin >> n >> m;
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  string s; cin >> s;
  map<string, tuple<int, int, int>> mp;
  rep(i, n) {
    rep(j, m) {
      if(j+2 > m) continue;
      mp[S[i].substr(j, 2)] = {j, j+2, i};
      if(j+3 > m) continue;
      mp[S[i].substr(j, 3)] = {j, j+3, i};
    }
  }
  vector<bool> dp(m+1);
  vector<pair<int, tuple<int, int, int>>> par(m+1, {-1, make_tuple(0, 0, 0)});
  dp[0] = true;
  rep(i, m) {
    if(!dp[i]) continue;
    if(i+2 > m) continue;
    if(mp.count(s.substr(i, 2))) {
      dp[i+2] = true;
      par[i+2] = {i, mp[s.substr(i, 2)]};
    }
    if(i+3 > m) continue;
    if(mp.count(s.substr(i, 3))) {
      dp[i+3] = true;
      par[i+3] = {i, mp[s.substr(i, 3)]};
    }
  }
  if(!dp[m]) {
    cout << -1 << endk;
  } else {
    vector<tuple<int, int, int>> ans;
    int tmp = m;
    while(tmp) {
      ans.push_back(par[tmp].second);
      assert(par[tmp].first >= 0);
      tmp = par[tmp].first;
    }
    reverse(all(ans));
    cout << ans.size() << endk;
    for(auto [l, r, i]: ans) {
      cout << l+1 << ' ' << r << ' ' << i+1 << endk;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
