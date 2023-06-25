#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, D; cin >> n >> D;
  vector<int> A(n); rep(i, n) cin >> A[i];
  auto bfs = [&](int n) {
    vector<ll> dist(n, longinf);
    queue<pair<int, ll>> q;
    rep(i, n) if(A[i] == 0) {
      q.push({i, 0});
      dist[i] = 0;
    }
    vector<bool> vis(n);
    while(!q.empty()) {
      auto [cur, d] = q.front(); q.pop();
      if(vis[cur]) continue;
      if(dist[cur] < d) continue;
      vis[cur] = true;
      int ne = (cur-D+n)%n;
      ll cost = 1;
      if(dist[ne] > dist[cur] + cost) {
        dist[ne] = dist[cur] + cost;
        q.push({ne, dist[ne]});
      }
    }
    return dist;
  };
  auto dist = bfs(n);
  rep(i, n) if(dist[i] == longinf) {
    cout << -1 << endk;
    return;
  }
  cout << *max_element(all(dist)) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
