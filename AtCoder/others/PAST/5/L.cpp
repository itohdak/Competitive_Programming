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
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  string s, t; cin >> s >> t;
  set<pair<int, int>> canErase;
  auto erasable = [&](int begin, int len) {
    assert(len%3==0);
    if(len == 3) {
      if(s.substr(begin, len) == t) return true;
    } else {
      rep(i, len) REP(j, i+1, len) REP(k, j+1, len) {
        if(s[begin+i] == t[0] &&
           s[begin+j] == t[1] &&
           s[begin+k] == t[2] &&
           (i == 0 || canErase.count({begin, i})) &&
           (j-i-1 == 0 || canErase.count({begin+i+1, j-i-1})) &&
           (k-j-1 == 0 || canErase.count({begin+j+1, k-j-1})) &&
           (len-k-1 == 0 || canErase.count({begin+k+1, len-k-1}))) return true;
      }
      for(int l=3; l<len; l+=3) {
        if(canErase.count({begin, l}) && canErase.count({begin+l, len-l})) return true;
      }
    }
    return false;
  };
  for(int m=3; m<=n; m+=3) {
    rep(i, n-m+1) {
      if(erasable(i, m)) {
        canErase.insert({i, m});
      }
    }
  }
  // cout << canErase << endk;
  vector<vector<int>> G(n);
  for(auto [begin, len]: canErase) {
    G[begin].push_back(begin+len);
  }
  vector<int> dp(n+1, -inf);
  dp[0] = 0;
  rep(i, n) {
    chmax(dp[i+1], dp[i]);
    for(auto ne: G[i]) {
      chmax(dp[ne], dp[i]+(ne-i)/3);
    }
  }
  cout << dp[n] << endk;
  return 0;
}
