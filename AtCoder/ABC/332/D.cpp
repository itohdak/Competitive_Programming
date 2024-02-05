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
  int h, w; cin >> h >> w;
  vector<vector<int>> A(h, vector<int>(w));
  vector<vector<int>> B(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> A[i][j];
  rep(i, h) rep(j, w) cin >> B[i][j];
  queue<pair<vector<int>, int>> q;
  set<vector<int>> vis;
  map<vector<int>, int> dist;
  vector<int> tmp;
  rep(i, h+w) tmp.push_back(i);
  q.push({tmp, 0});
  while(q.size()) {
    auto [cur, d] = q.front(); q.pop();
    if(vis.count(cur)) continue;
    vis.insert(cur);
    if(d > dist[cur]) continue;
    rep(i, h-1) {
      vector<int> ne = cur;
      swap(ne[i], ne[i+1]);
      if(!vis.count(ne) && (!dist.count(ne) || dist[ne] > d+1)) {
        if(!dist.count(ne)) dist[ne] = inf;
        chmin(dist[ne], d+1);
        q.push({ne, dist[ne]});
      }
    }
    rep(i, w-1) {
      vector<int> ne = cur;
      swap(ne[h+i], ne[h+i+1]);
      if(!vis.count(ne) && (!dist.count(ne) || dist[ne] > d+1)) {
        if(!dist.count(ne)) dist[ne] = inf;
        chmin(dist[ne], d+1);
        q.push({ne, dist[ne]});
      }
    }
  }
  int ans = inf;
  for(auto [v, d]: dist) {
    bool ok = true;
    rep(i, h) {
      rep(j, w) {
        if(A[v[i]][v[h+j]-h] != B[i][j]) ok = false;
        if(!ok) break;
      }
      if(!ok) break;
    }
    if(ok) {
      chmin(ans, d);
    }
  }
  cout << (ans==inf ? -1 : ans) << endk;
  return 0;
}
