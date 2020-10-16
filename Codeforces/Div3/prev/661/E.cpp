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
  ll s; cin >> s;
  vector<vector<pair<int, ll>>> G(n);
  rep(i, n-1) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    ll w; cin >> w;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
  vector<int> nLeaves(n);
  priority_queue<pair<ll, pair<ll, int>>> q;
  ll sum = 0;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    if(G[cur].size() - (par != -1) == 0) {
      nLeaves[cur]++;
    }
    for(auto ele: G[cur]) {
      int ne = ele.first;
      if(ne != par) {
        dfs(dfs, ne, cur);
        nLeaves[cur] += nLeaves[ne];
        q.push(make_pair((ele.second-ele.second/2)*nLeaves[ne], make_pair(ele.second, nLeaves[ne])));
        sum += ele.second * nLeaves[ne];
      }
    }
  };
  dfs(dfs, 0, -1);
  int ans = 0;
  while(sum > s) {
    auto ele = q.top(); q.pop();
    ans++;
    sum -= ele.first;
    ll w = ele.second.first;
    w /= 2;
    int l = ele.second.second;
    q.push(make_pair((w-w/2)*l, make_pair(w, l)));
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
