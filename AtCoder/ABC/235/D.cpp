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

int shift(int i) {
  deque<int> D;
  int tmp = i;
  while(tmp) {
    D.push_back(tmp%10);
    tmp /= 10;
  }
  D.push_back(D.front());
  D.pop_front();
  int ret = 0;
  while(D.size()) {
    ret = ret * 10 + D.back();
    D.pop_back();
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll a, n; cin >> a >> n;
  int mx = 10000000;
  vector<vector<edge>> G(mx);
  rep(i, mx) {
    if(i) {
      if(i*a < mx) {
        G[i].push_back({(int)(i*a), 1});
      }
      if(i >= 10 && i%10) {
        int ne = shift(i);
        if(ne < mx) {
          G[i].push_back({ne, 1});
        }
      }
    }
  }
  dijkstra(mx, G, 1);
  cout << (dist[n]==longinf ? -1 : dist[n]) << endk;
  return 0;
}
