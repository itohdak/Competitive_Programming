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

using P = pair<ll, int>;

vector<ll> dist;
vector<vector<int>> par;
void dijkstra(int n, vector<set<int>>& G, int s) {
  priority_queue<P, vector<P>, greater<P>> q;
  dist.assign(n, longinf);
  par.assign(n, vector<int>());
  dist[s] = 0;
  q.push({0, s});
  while(q.size()) {
    auto [d, cur] = q.top(); q.pop();
    if(dist[cur] < d) continue;
    for(auto ne: G[cur]) {
      ll cost = 1;
      if(dist[ne] > dist[cur] + cost) {
        dist[ne] = dist[cur] + cost;
        par[ne] = vector<int>();
        par[ne].push_back(cur);
        q.push({dist[ne], ne});
      } else if(dist[ne] == dist[cur] + cost) {
        par[ne].push_back(cur);
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<set<int>> G(n);
  vector<pair<int, int>> P(m);
  rep(i, m) {
    int s, t; cin >> s >> t;
    s--; t--;
    P[i] = {s, t};
    G[s].insert(t);
  }
  dijkstra(n, G, 0);
  auto DIST = dist;
  auto PAR = par;
  set<int> st;
  auto bfs = [&](int s, int n) {
    queue<pair<int, ll>> q;
    q.push({s, 0});
    vector<int> D(n, inf);
    D[s] = 0;
    vector<bool> vis(n);
    while(!q.empty()) {
      auto [cur, d] = q.front(); q.pop();
      if(vis[cur]) continue;
      if(D[cur] < d) continue;
      st.insert(cur);
      vis[cur] = true;
      for(auto ne: PAR[cur]) {
        if(D[ne] > D[cur] + 1) {
          D[ne] = D[cur] + 1;
          q.push({ne, D[cur] + 1});
        }
      }
    }
  };
  bfs(n-1, n);
  map<int, int> cnt;
  for(auto i: st) cnt[DIST[i]]++;
  if(DIST[n-1]==longinf) {
    rep(i, m) cout << -1 << endk;
  } else {
    rep(i, m) {
      auto [s, t] = P[i];
      if(st.count(s) && st.count(t) && DIST[s]+1 == DIST[t] && cnt[DIST[t]] == 1) {
        G[s].erase(t);
        dijkstra(n, G, 0);
        cout << (dist[n-1]==longinf ? -1 : dist[n-1]) << endk;
        G[s].insert(t);
      } else {
        cout << DIST[n-1] << endk;
      }
    }
  }
  return 0;
}
