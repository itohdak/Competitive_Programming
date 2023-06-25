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
void dijkstra(int n, vector<set<int>>& G, int s) {
  priority_queue<P, vector<P>, greater<P>> q;
  dist.assign(n, longinf);
  par.assign(n, -1);
  dist[s] = 0;
  q.push({0, s});
  while(q.size()) {
    auto [d, cur] = q.top(); q.pop();
    if(dist[cur] < d) continue;
    for(auto ne: G[cur]) {
      if(dist[ne] > dist[cur] + 1) {
        dist[ne] = dist[cur] + 1;
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
  vector<set<int>> G(n);
  vector<pair<int, int>> P(m);
  rep(i, m) {
    int s, t; cin >> s >> t;
    s--; t--;
    P[i] = {s, t};
    G[s].insert(t);
  }
  dijkstra(n, G, 0);
  set<int> st;
  int tmp = n-1;
  while(tmp != -1) {
    st.insert(tmp);
    tmp = par[tmp];
  }
  auto d = dist;
  rep(i, m) {
    auto [s, t] = P[i];
    if(st.count(s) && st.count(t) && d[s]+1 == d[t]) {
      G[s].erase(t);
      dijkstra(n, G, 0);
      G[s].insert(t);
      cout << (dist[n-1]==longinf ? -1 : dist[n-1]) << endk;
    } else {
      cout << (d[n-1]==longinf ? -1 : d[n-1]) << endk;
    }
  }
  return 0;
}
