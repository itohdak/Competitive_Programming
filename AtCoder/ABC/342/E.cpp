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
  vector<vector<tuple<int, ll, ll, ll, ll>>> G(n);
  rep(i, m) {
    ll l, d, k, c; cin >> l >> d >> k >> c;
    int a, b; cin >> a >> b;
    a--; b--;
    G[b].push_back({a, l, d, k, c});
  }

  priority_queue<pair<ll, int>> q;
  vector<ll> dist(n, -longinf);
  dist[n-1] = longinf;
  q.push({longinf, n-1});
  while(q.size()) {
    auto [d0, cur] = q.top(); q.pop();
    if(dist[cur] > d0) continue;
    for(auto [ne, l, d, k, c]: G[cur]) {
      // l ... l+(k-1)*d
      int m = min((d0-c-l)/d, k-1);
      if(m < 0) continue;
      ll dnext = l+m*d;
      if(dist[ne] < dnext) {
        dist[ne] = dnext;
        q.push({dist[ne], ne});
      }
    }
  }
  rep(i, n-1) {
    if(dist[i] == -longinf) cout << "Unreachable" << endk;
    else cout << dist[i] << endk;
  }
  return 0;
}
