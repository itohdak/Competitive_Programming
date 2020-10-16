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
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> col(n, -1);
  auto bfs = [&](int s) {
    queue<pair<int, int>> q;
    q.push({s, 0});
    while(!q.empty()) {
      auto ele = q.front();
      int cur = ele.first;
      q.pop();
      if(col[cur] != -1) continue;
      col[cur] = ele.second;
      for(int ne: G[cur]) {
        if(col[ne] == -1) {
          q.push({ne, 1-col[cur]});
        }
      }
    }
  };
  bfs(0);
  int sum = accumulate(all(col), 0LL);
  if(sum > n/2) {
    cout << n - sum << endk;
    rep(i, n) {
      if(col[i] == 0) cout << i+1 << ' ';
    }
    cout << endk;
  } else {
    cout << sum << endk;
    rep(i, n) {
      if(col[i] == 1) cout << i+1 << ' ';
    }
    cout << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
