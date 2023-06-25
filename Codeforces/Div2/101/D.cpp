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
  int n; ll l; cin >> n >> l;
  vector<tuple<ll, ll, ll, ll>> T(n);
  vector<ll> V;
  rep(i, n) {
    ll x, d, t, p; cin >> x >> d >> t >> p;
    T[i] = {x, d, t, p};
    V.push_back(x-p);
    V.push_back(x+d);
  }
  V.push_back(0);
  V.push_back(l);
  sort(all(V));
  V.erase(unique(all(V)), end(V));
  auto id = [&](ll v) {
    auto itr = lower_bound(all(V), v);
    assert(*itr == v);
    return itr - begin(V);
  };
  int m = V.size();
  vector<vector<edge>> G(m);
  rep(i, n) {
    auto [x, d, t, p] = T[i];
    int from = id(x-p), to = id(x+d);
    G[from].push_back({to, p+t});
  }
  rep(i, m) {
    if(i == 0) continue;
    G[i-1].push_back({i, V[i]-V[i-1]});
    if(V[i-1] >= 0) G[i].push_back({i-1, V[i]-V[i-1]});
  }
  int s = id(0), t = id(l);
  dijkstra(m, G, s);
  vector<int> path;
  int tmp = t;
  while(tmp != -1) {
    path.push_back(tmp);
    tmp = par[tmp];
  }
  reverse(all(path));
  map<tuple<ll, ll, ll>, int> mp;
  rep(i, n) {
    auto [x, d, t, p] = T[i];
    ll xfrom = x-p, xto = x+d;
    ll tall = p+t;
    mp[{xfrom, xto, tall}] = i;
  }
  vector<int> used;
  rep(i, path.size()) {
    if(i == 0) continue;
    int from = path[i-1], to = path[i];
    ll xfrom = V[from], xto = V[to];
    ll tall = dist[to]-dist[from];
    if(tall != abs(xto-xfrom)) {
      assert(mp.count({xfrom, xto, tall}));
      used.push_back(mp[{xfrom, xto, tall}]);
    }
  }
  cout << dist[t] << endk;
  cout << used.size() << endk;
  for(int u: used) {
    cout << u+1 << ' ';
  }
  cout << endk;
  return 0;
}
