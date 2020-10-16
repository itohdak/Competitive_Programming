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
#define fi first
#define se second

void solve() {
  int n, m; cin >> n >> m;
  vector<pair<int, int>> P(n);
  vector<pair<int, int>> Q(m);
  rep(i, n) cin >> P[i].first >> P[i].second;
  rep(i, m) cin >> Q[i].first >> Q[i].second;
  set<pair<int, int>> st;
  rep(i, n) rep(j, m) {
    int x = Q[j].fi-P[i].fi;
    int y = Q[j].se-P[i].se;
    if(x < 0 || y < 0) continue;
    st.insert({x, y});
  }
  multiset<ll> mostR;
  for(auto ele: st) mostR.insert(ele.second);
  int ans = inf;
  for(int i=0; i<=1000005; i++) {
    if(mostR.empty()) {
      chmin(ans, i);
      break;
    } else {
      chmin(ans, i+*mostR.rbegin()+1);
    }
    for(auto itr=st.lower_bound({i, 0}); itr!=st.upper_bound({i, inf}); itr++) {
      mostR.erase(mostR.find(itr->second));
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
