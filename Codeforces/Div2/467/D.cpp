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

struct edge {
  int to;
  ll cost;
  edge(int t, ll c): to(t), cost(c) {};
};

using P = pair<ll, int>;

vector<ll> dist;
vector<int> par;
void dijkstra(int n, vector<vector<edge>>& G, int s) {
  priority_queue<P, vector<P>, greater<P>> q;
  dist.assign(n, longinf);
  par.assign(n, -1);
  dist[s] = 0;
  q.push({0, s});
  while(q.size()) {
    auto [d, cur] = q.top(); q.pop();
    if(dist[cur] < d) continue;
    for(auto [ne, cost]: G[cur]) {
      if(dist[ne] > dist[cur] + cost) {
        dist[ne] = dist[cur] + cost;
        q.push({dist[ne], ne});
        par[ne] = cur;
      }
    }
  }
}

vector<vector<int>> G2;
vector<int> Tpl;
/* topological sort with loop detection */
vector<bool> seen, finished;
bool dfs2(int cur, int par) {
  if(seen[cur] && !finished[cur]) return true;
  if(seen[cur] || finished[cur]) return false;
  seen[cur] = true;
  bool ret = false;
  for(int ne: G2[cur]) {
    // if(ne == par) continue;
    ret |= dfs2(ne, cur);
  }
  finished[cur] = true;
  Tpl.push_back(cur);
  return ret;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<vector<int>> Gorig(n);
  vector<vector<edge>> G(2*n);
  rep(i, n) {
    int k; cin >> k;
    rep(j, k) {
      int to; cin >> to;
      to--;
      Gorig[i].push_back(to);
      G[i].push_back({n+to, 1});
      G[n+i].push_back({to, 1});
    }
  }
  int s; cin >> s;
  s--;
  dijkstra(2*n, G, s);
  // cout << dist << endk;
  rep(i, n) {
    if(Gorig[i].size() == 0 && dist[n+i] != longinf) {
      cout << "Win" << endk;
      vector<int> ans;
      int tmp = n+i;
      while(tmp != s) {
        ans.push_back(tmp%n);
        tmp = par[tmp];
      }
      ans.push_back(s);
      reverse(all(ans));
      for(int a: ans) cout << a+1 << ' ';
      cout << endk;
      return 0;
    }
  }
  G2.assign(n, vector<int>());
  rep(i, n) {
    if(dist[i] != longinf || dist[n+i] != longinf) {
      for(auto [ne, _]: G[i]) {
        G2[i].push_back(ne%n);
      }
    }
  }
  seen.assign(n, false);
  finished.assign(n, false);
  bool ret = false;
  rep(i, n) ret |= dfs2(i, -1);
  cout << (ret ? "Draw" : "Lose") << endk;
  return 0;
}
