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
  int n, m, q; cin >> n >> m >> q;
  vector<vector<int>> id(n*m);
  vector<vector<int>> path;
  auto dfs = [&](auto dfs, int x, int y, int c) -> void {
    if(x >= n || y >= m) return;
    int cur = x*m+y;
    id[cur].push_back(path.size()-1);
    path.back().push_back(cur);
    dfs(dfs, x+(c==0), y+(c!=0), 1-c);
  };
  rep(i, n) if(i < n-1) {
    path.push_back(vector<int>());
    dfs(dfs, i, 0, 0);
  }
  rep(j, m) if(j < m-1) {
    path.push_back(vector<int>());
    dfs(dfs, 0, j, 1);
  }
  ll ans = 0;
  for(auto v: path) {
    ll sz = v.size();
    ans += sz*(sz-1)/2;
  }
  set<int> st;
  vector<set<int>> st_path(path.size());
  rep(i, q) {
    int x, y; cin >> x >> y;
    x--; y--;
    int cur = x*m+y;
    for(int j: id[cur]) {
      auto p = path[j];
      auto lb = st_path[j].lower_bound(cur+1);
      int lbi = -1;
      if(lb == st_path[j].end()) {
        lbi = p.size();
      } else {
        lbi = lower_bound(all(p), *lb) - begin(p);
      }
      auto ub = st_path[j].upper_bound(cur-1);
      int ubi = -1;
      if(ub == st_path[j].begin()) {
        ubi = -1;
      } else {
        ub--;
        ubi = lower_bound(all(p), *ub) - begin(p);
      }
      int curi = lower_bound(all(p), cur) - begin(p);
      if(st.count(cur)) {
        ans += 1LL*(lbi-ubi-1)*(lbi-ubi-2)/2;
        ans -= 1LL*(curi-ubi-1)*(curi-ubi-2)/2;
        ans -= 1LL*(lbi-curi-1)*(lbi-curi-2)/2;
        st_path[j].erase(cur);
      } else {
        ans -= 1LL*(lbi-ubi-1)*(lbi-ubi-2)/2;
        ans += 1LL*(curi-ubi-1)*(curi-ubi-2)/2;
        ans += 1LL*(lbi-curi-1)*(lbi-curi-2)/2;
        st_path[j].insert(cur);
      }
    }
    if(st.count(cur)) {
      st.erase(cur);
    } else {
      st.insert(cur);
    }
    cout << ans+(n*m)-st.size() << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
