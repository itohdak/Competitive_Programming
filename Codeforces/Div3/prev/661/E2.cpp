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
  vector<vector<tuple<int, ll, int>>> G(n);
  rep(i, n-1) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    ll w; cin >> w;
    int c; cin >> c;
    G[u].push_back({v, w, c});
    G[v].push_back({u, w, c});
  }
  vector<int> nLeaves(n);
  priority_queue<pair<ll, pair<ll, int>>> q1, q2;
  ll sum = 0;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    if(G[cur].size() - (par != -1) == 0) {
      nLeaves[cur]++;
    }
    for(auto ele: G[cur]) {
      int ne = get<0>(ele);
      ll w = get<1>(ele);
      int c = get<2>(ele);
      if(ne != par) {
        dfs(dfs, ne, cur);
        nLeaves[cur] += nLeaves[ne];
        if(c == 1) {
          q1.push(make_pair((w-w/2)*nLeaves[ne], make_pair(w, nLeaves[ne])));
        } else {
          q2.push(make_pair((w-w/2)*nLeaves[ne], make_pair(w, nLeaves[ne])));
        }
        sum += w * nLeaves[ne];
      }
    }
  };
  dfs(dfs, 0, -1);
  vector<ll> d1 = {0}, d2 = {0};
  {
    ll sum = 0;
    while(!q1.empty()) {
      auto ele = q1.top(); q1.pop();
      int l = ele.second.second;
      ll w = ele.second.first;
      w /= 2;
      sum += ele.first;
      d1.push_back(sum);
      if(w-w/2) q1.push(make_pair((w-w/2)*l, make_pair(w, l)));
    }
  }
  {
    ll sum = 0;
    while(!q2.empty()) {
      auto ele = q2.top(); q2.pop();
      int l = ele.second.second;
      ll w = ele.second.first;
      w /= 2;
      sum += ele.first;
      d2.push_back(sum);
      if(w-w/2) q2.push(make_pair((w-w/2)*l, make_pair(w, l)));
    }
  }
  int ans = inf;
  ll diff = sum - s;
  rep(i, d1.size()) {
    ll d = d1[i];
    int j = lower_bound(all(d2), diff-d) - begin(d2);
    if(j == (int)d2.size()) continue;
    chmin(ans, i*1+j*2);
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
