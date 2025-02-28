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
  int n, k; cin >> n >> k;
  vector<int> C(n); rep(i, n) cin >> C[i];
  vector<int> P(n); rep(i, n) cin >> P[i];
  map<int, int> mp;
  rep(i, n) {
    if(!mp.count(C[i])) mp[C[i]] = inf;
    chmin(mp[C[i]], P[i]);
  }
  if(mp.size() < k) cout << -1 << endk;
  else {
    vector<int> cost;
    for(auto [_, p]: mp) cost.push_back(p);
    sort(all(cost));
    ll ans = 0;
    rep(i, k) ans += cost[i];
    cout << ans << endk;
  }
  return 0;
}
