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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<vector<pair<int, pair<ll, ll>>>> G(n);
  rep(i, m) {
    int a, b; ll c, d; cin >> a >> b >> c >> d;
    a--; b--;
    G[a].push_back({b, {c, d}});
    G[b].push_back({a, {c, d}});
  }
  using P = pair<ll, int>;
  priority_queue<P, vector<P>, greater<P>> q;
  vector<ll> dist(n, longinf);
  dist[0] = 0;
  q.push({0, 0});
  while(q.size()) {
    auto [dtmp, cur] = q.top(); q.pop();
    if(dist[cur] < dtmp) continue;
    for(auto [ne, cost]: G[cur]) {
      auto [c, d] = cost;
      ll sqrtd = sqrt(d);
      if(abs(sqrtd*sqrtd-d) > abs((sqrtd+1)*(sqrtd+1)-d)) sqrtd++;
      ll tmp = sqrtd-1;
      if(dtmp <= tmp) {
        if(dist[ne] > tmp + c + d/(tmp+1)) {
          dist[ne] = tmp + c + d/(tmp+1);
          q.push({dist[ne], ne});
        }
      } else {
        if(dist[ne] > dtmp + c + d/(dtmp+1)) {
          dist[ne] = dtmp + c + d/(dtmp+1);
          q.push({dist[ne], ne});
        }
      }
    }
  }
  // cout << dist << endk;
  cout << (dist[n-1]==longinf ? -1 : dist[n-1]) << endk;
  return 0;
}
