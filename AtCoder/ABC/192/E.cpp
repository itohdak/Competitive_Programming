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

using P = pair<ll, int>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, x, y; cin >> n >> m >> x >> y;
  x--; y--;
  vector<vector<tuple<int, ll, ll>>> G(n);
  rep(i, m) {
    int a, b; ll t, k;
    cin >> a >> b >> t >> k;
    a--; b--;
    G[a].push_back({b, t, k});
    G[b].push_back({a, t, k});
  }
  priority_queue<P, vector<P>, greater<P>> q;
  vector<ll> dist(n, longinf);
  dist[x] = 0;
  q.push({0, x});
  while(q.size()) {
    auto [d, cur] = q.top(); q.pop();
    if(dist[cur] < d) continue;
    for(auto [ne, t, k]: G[cur]) {
      if(dist[ne] > (dist[cur]+k-1)/k*k + t) {
        dist[ne] = (dist[cur]+k-1)/k*k + t;
        q.push({dist[ne], ne});
      }
    }
  }
  cout << (dist[y] == longinf ? -1 : dist[y]) << endk;
  return 0;
}
