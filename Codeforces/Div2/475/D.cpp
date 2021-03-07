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
  vector<int> P(n);
  vector<set<int>> G(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
    if(P[i] != -1) {
      G[P[i]].insert(i);
      G[i].insert(P[i]);
    }
  }
  if(n % 2 == 0) {
    cout << "NO" << endk;
    return 0;
  }
  vector<int> ans;
  deque<int> child;
  auto destroy = [&](int i) {
    for(int ne: G[i]) {
      assert(G[ne].count(i));
      G[ne].erase(i);
    }
    G[i].clear();
  };
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    // cout << cur << ' ' << par << endl;
    // cout << G << endl;
    set<int> st = G[cur];
    for(int ne: st) {
      if(ne != par) dfs(dfs, ne, cur);
    }
    child.push_back(cur);
    while(child.size() && G[child.back()].size() % 2 == 0) {
      int back = child.back(); child.pop_back();
      ans.push_back(back);
      destroy(back);
    }
  };
  dfs(dfs, 0, -1);
  assert(ans.size() == n);
  cout << "YES" << endk;
  for(int i: ans) cout << i+1 << endk;
  return 0;
}
