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
  ll n; int m; cin >> n >> m;
  vector<ll> A(m), B(m), C(m);
  vector<ll> F;
  rep(i, m) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--; B[i]--;
    F.push_back(A[i]);
    F.push_back(B[i]);
  }
  F.push_back(0);
  F.push_back(n-1);
  sort(all(F));
  F.erase(unique(all(F)), end(F));
  auto id = [&](int x) {
    return lower_bound(all(F), x) - begin(F);
  };
  int k = F.size();
  vector<vector<edge>> G(k);
  rep(i, m) {
    int s = id(A[i]), t = id(B[i]);
    G[s].push_back({t, C[i]});
    G[t].push_back({s, C[i]});
  }
  rep(i, k-1) {
    G[i].push_back({i+1, F[i+1]-F[i]});
    G[i+1].push_back({i, F[i+1]-F[i]});
  }
  dijkstra(k, G, 0);
  cout << dist[k-1] << endk;
  return 0;
}
