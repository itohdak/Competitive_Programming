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
  vector<pair<ll, ll>> pos(n);
  map<ll, vector<pair<ll, ll>>> level;
  level[0].push_back({0, 0});
  rep(i, n) {
    cin >> pos[i].first >> pos[i].second;
    level[max(pos[i].first, pos[i].second)].push_back(pos[i]);
  }
  for(auto& ele: level) {
    sort(all(ele.second), [&](pair<ll, ll> p1, pair<ll, ll> p2) {
      return p1.first-p1.second < p2.first-p2.second;
    });
  }
  int m = level.size();
  vector<vector<ll>> dp(m, vector<ll>(2, longinf));
  dp[0][0] = dp[0][1] = 0;
  auto tmp = level.begin();
  auto ne = ++level.begin();
  auto distance = [&](pair<ll, ll> p1, pair<ll, ll> p2) {
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
  };
  rep(i, m-1) {
    auto dconst = distance(ne->second.front(), ne->second.back());
    rep(j, 2) rep(k, 2) {
      chmin(dp[i+1][k],
            dp[i][j]
            + distance((j ? tmp->second.front() : tmp->second.back()),
                       (k ? ne->second.back() : ne->second.front()))
            + dconst);
    }
    tmp++; ne++;
  }
  cout << *min_element(all(dp[m-1])) << endk;
  return 0;
}
