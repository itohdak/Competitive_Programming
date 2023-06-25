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
  ll h, w, n; cin >> h >> w >> n;

  ll sx, sy; cin >> sx >> sy;
  sx--; sy--;
  ll s = sx*w+sy;

  ll gx, gy; cin >> gx >> gy;
  gx--; gy--;
  ll g = gx*w+gy;

  vector<ll> X(n), Y(n);
  map<ll, set<ll>> R, C;
  rep(i, n) {
    cin >> X[i] >> Y[i];
    X[i]--; Y[i]--;
    R[X[i]].insert(Y[i]);
    C[Y[i]].insert(X[i]);
  }

  map<ll, ll> dist;
  queue<pair<ll, ll>> q;
  set<ll> vis;
  q.push({s, 0});
  dist[s] = 0;
  while(!q.empty()) {
    auto [cur, d] = q.front(); q.pop();
    ll x = cur/w, y = cur%w;
    if(vis.count(cur)) continue;
    if(dist[cur] < d) continue;
    vis.insert(cur);
    if(R[x].lower_bound(y) != R[x].end()) {
      auto itr = R[x].lower_bound(y);
      ll nx = x, ny = *itr-1;
      ll ne = nx*w+ny;
      if(!dist.count(ne) || dist[ne] > dist[cur] + 1) {
        dist[ne] = dist[cur] + 1;
        q.push({ne, dist[ne]});
      }
    }
    if(R[x].upper_bound(y-1) != R[x].begin()) {
      auto itr = R[x].upper_bound(y-1);
      ll nx = x, ny = *(--itr)+1;
      ll ne = nx*w+ny;
      if(!dist.count(ne) || dist[ne] > dist[cur] + 1) {
        dist[ne] = dist[cur] + 1;
        q.push({ne, dist[ne]});
      }
    }
    if(C[y].lower_bound(x) != C[y].end()) {
      auto itr = C[y].lower_bound(x);
      ll nx = *itr-1, ny = y;
      ll ne = nx*w+ny;
      if(!dist.count(ne) || dist[ne] > dist[cur] + 1) {
        dist[ne] = dist[cur] + 1;
        q.push({ne, dist[ne]});
      }
    }
    if(C[y].upper_bound(x-1) != C[y].begin()) {
      auto itr = C[y].upper_bound(x-1);
      ll nx = *(--itr)+1, ny = y;
      ll ne = nx*w+ny;
      if(!dist.count(ne) || dist[ne] > dist[cur] + 1) {
        dist[ne] = dist[cur] + 1;
        q.push({ne, dist[ne]});
      }
    }
  }
  cout << (!dist.count(g) ? -1 : dist[g]) << endk;
  return 0;
}
