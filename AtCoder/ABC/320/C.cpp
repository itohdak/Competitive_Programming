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
  int m; cin >> m;
  vector<string> S(3);
  rep(i, 3) cin >> S[i];
  vector<vector<vector<int>>> pos(3, vector<vector<int>>(10));
  rep(i, 3) {
    rep(j, m) {
      pos[i][S[i][j]-'0'].push_back(j);
    }
  }
  rep(i, 3) {
    rep(j, 10) {
      int sz = pos[i][j].size();
      rep(k, sz) {
	pos[i][j].push_back(pos[i][j][k]+m);
      }
    }
  }
  set<int> id = {0, 1, 2};
  int ans = inf;
  auto dfs = [&](auto dfs, int cur, int t) -> void {
    if(id.empty()) {
      chmin(ans, cur);
      return;
    }
    rep(i, 3) {
      if(id.count(i)) {
	auto itr = lower_bound(all(pos[i][t]), (cur+(id.size()<3))%m);
	if(itr == pos[i][t].end()) continue;
	int next = *itr - ((cur+(id.size()<3))%m) + (cur+(id.size()<3));
	id.erase(i);
	dfs(dfs, next, t);
	id.insert(i);
      }
    }
  };
  rep(i, 10) {
    dfs(dfs, 0, i);
  }
  cout << (ans == inf ? -1 : ans) << endk;
  return 0;
}
