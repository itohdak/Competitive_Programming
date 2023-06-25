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

void solve() {
  int n, k; cin >> n >> k;
  if(k%2) {
    cout << "IMPOSSIBLE" << endk;
    return;
  }
  int diff = n*n-1-k;
  diff /= 2;
  int offset = 1;
  vector<pair<int, int>> ans;
  for(int i=n; i>=3; i-=2) {
    rep(k, (i==3?3:4)) {
      int j = 2*i-3-k;
      if(diff >= j) {
        diff -= j;
        int from = offset+1+(i-1)*k;
        int to = from+4*i-5-2*k;
        ans.push_back({from, to});
        break;
      }
    }
    offset += (i-1)*4;
  }
  if(diff != 0) {
    cout << "IMPOSSIBLE" << endk;
  } else {
    cout << ans.size() << endk;
    for(auto [f, t]: ans) cout << f << ' ' << t << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
