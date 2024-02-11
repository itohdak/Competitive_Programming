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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> A(n), B(n);
  map<int, int> mp;
  rep(i, n) {
    cin >> A[i];
    mp[m-A[i]] = 0;
  }
  rep(i, n) {
    cin >> B[i];
    mp[B[i]] = 0;
  }
  {
    int i = 0;
    for(auto& [k, v]: mp) v = i++;
  }
  int k = mp.size();
  vector<vector<edge>> G(n+k);
  bool first = true;
  int prev = -1;
  for(auto [k, v]: mp) {
    if(first) {
      first = false;
    } else {
      G[n+v-1].push_back({n+v, k-prev});
    }
    prev = k;
  }
  G[n+k-1].push_back({n, mp.begin()->first-prev+m});
  rep(i, n) {
    G[i].push_back({n+mp[m-A[i]], 0});
    G[n+mp[B[i]]].push_back({i, 0});
  }
  dijkstra(n+k, G, 0);
  cout << dist[n-1] << endk;
  return 0;
}
