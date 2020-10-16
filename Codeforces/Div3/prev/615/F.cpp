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
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> d(n);
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    d[cur] = (par==-1 ? 0: d[par]+1);
    for(int ne: G[cur]) {
      if(ne != par) dfs(dfs, ne, cur);
    }
  };
  dfs(dfs, 0, -1);
  int mxi = max_element(all(d)) - begin(d);
  dfs(dfs, mxi, -1);
  int mxi2 = max_element(all(d)) - begin(d);
  int mxd = d[mxi2];
  vector<int> d1(n);
  copy(all(d), begin(d1));
  dfs(dfs, mxi2, -1);
  vector<int> d2(n);
  copy(all(d), begin(d2));
  int mx = -1;
  int mxi3 = 0;
  rep(i, n) {
    if(i == mxi || i == mxi2) continue;
    if(mx < (d1[i]+d2[i]-mxd)/2) {
      mx = (d1[i]+d2[i]-mxd)/2;
      mxi3 = i;
    }
  }
  cout << mxd + mx << endk;
  cout << mxi+1 << ' ' << mxi2+1 << ' ' << mxi3+1 << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
