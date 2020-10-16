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
  int n;
  cin >> n;
  ll pw = 1;
  while(pw * 2 <= n) pw *= 2;
  vector<pair<int, int>> ans;
  auto dfs = [&](auto dfs, int l, int r) -> void {
    int d = r-l;
    if(d == 1) return;
    rep(i, d/2) ans.push_back({l+i, l+d/2+i});
    dfs(dfs, l, l+d/2);
    dfs(dfs, l+d/2, r);
  };
  dfs(dfs, 0, pw);
  dfs(dfs, n-pw, n);
  cout << ans.size() << endk;
  for(auto ele: ans) cout << ele.first+1 << ' ' << ele.second+1 << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
