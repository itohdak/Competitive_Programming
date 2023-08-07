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
  int n; cin >> n;
  vector<vector<int>> G(n);
  rep(i, n) {
    if(i == 0) continue;
    int p; cin >> p; p--;
    G[p].push_back(i);
    G[i].push_back(p);
  }
  vector<int> cnt(n);
  ll ans = 0;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    cnt[cur]++;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      dfs(dfs, ne, cur);
      cnt[cur] += cnt[ne];
    }
    set<int> st;
    st.insert(0);
    vector<int> A;
    for(int ne: G[cur]) {
      if(ne == par) continue;
      A.push_back(cnt[ne]);
    }
    int m = A.size();
    rep(i, m) {
      set<int> st2;
      for(auto j: st) {
	st2.insert(j+A[i]);
	st2.insert(j);
      }
      st = st2;
    }
    ll mx = 0;
    for(auto j: st) {
      chmax(mx, 1LL*j*(cnt[cur]-1-j));
    }
    ans += mx;
  };
  dfs(dfs, 0, -1);
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
