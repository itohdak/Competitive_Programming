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
  int cost;
  edge(int t, int c): to(t), cost(c) {};
};

using P = pair<int, int>;

vector<int> dist;
void dijkstra(int n, vector<vector<edge>>& G, int s) {
  priority_queue<P, vector<P>, greater<P>> q;
  dist.assign(n, inf);
  dist[s] = 0;
  q.push({0, s});
  while(q.size()) {
    auto [d, cur] = q.top(); q.pop();
    if(dist[cur] < d) continue;
    for(auto [ne, cost]: G[cur]) {
      if(dist[ne] > dist[cur] + cost) {
        dist[ne] = dist[cur] + cost;
        q.push({dist[ne], ne});
      }
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> S(n); rep(i, n) cin >> S[i];
  vector<int> C(n); rep(i, n) cin >> C[i];
  vector<vector<edge>> G(3*n+2);
  rep(i, n) REP(j, i+1, n) {
    if(S[i] < S[j]) {
      rep(k, 2) {
        G[k*n+i].push_back({(k+1)*n+j, C[i]});
      }
    }
  }
  rep(i, n) G[3*n].push_back({i, 0});
  rep(i, n) G[2*n+i].push_back({3*n+1, C[i]});
  dijkstra(3*n+2, G, 3*n);
  cout << (dist.back() == inf ? -1 : dist.back()) << endk;
  return 0;
}
