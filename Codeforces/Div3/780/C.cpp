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

void solve() {
  string s; cin >> s;
  int n = s.size();
  vector<vector<int>> pos(26);
  rep(i, n) {
    pos[s[i]-'a'].push_back(i);
  }
  vector<int> dp(n+1, inf);
  dp[0] = 0;
  rep(i, n) {
    chmin(dp[i+1], dp[i]+1);
    auto itr = lower_bound(all(pos[s[i]-'a']), i+1);
    if(itr == end(pos[s[i]-'a'])) continue;
    chmin(dp[*itr+1], dp[i]+*itr-i-1);
  }
  cout << dp[n] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
