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
  map<int, set<ll>> mp;
  rep(i, n) {
    ll x; int c; cin >> x >> c;
    mp[c].insert(x);
  }
  int m = mp.size();
  vector<vector<ll>> dp(m+1, vector<ll>(2, longinf));
  dp[0][0] = dp[0][0] = 0;
  vector<ll> mn, mx;
  mn.push_back(0);
  mx.push_back(0);
  for(auto [c, st]: mp) {
    mn.push_back(*st.begin());
    mx.push_back(*st.rbegin());
  }
  rep(i, m) {
    chmin(dp[i+1][0], dp[i][0]+abs(mn[i]-mx[i+1])+(mx[i+1]-mn[i+1]));
    chmin(dp[i+1][0], dp[i][1]+abs(mx[i]-mx[i+1])+(mx[i+1]-mn[i+1]));
    chmin(dp[i+1][1], dp[i][0]+abs(mn[i]-mn[i+1])+(mx[i+1]-mn[i+1]));
    chmin(dp[i+1][1], dp[i][1]+abs(mx[i]-mn[i+1])+(mx[i+1]-mn[i+1]));
  }
  cout << min(dp[m][0]+abs(mn[m]), dp[m][1]+abs(mx[m])) << endk;
  return 0;
}
