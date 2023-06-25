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

vector<vector<ll>> dist;

void warshall_floyd(int n) {
  rep(i, n) rep(j, n) rep(k, n) {
    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  dist.assign(n, vector<ll>(n, longinf));
  rep(i, n) dist[i][i] = 0;
  rep(i, m) {
    int a, b; ll c; cin >> a >> b >> c;
    a--; b--;
    dist[a][b] = c;
  }
  ll ans = 0;
  rep(i, n) {
    rep(j, n) rep(k, n) {
      dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
    }
    rep(j, n) rep(k, n) {
      ans += (dist[j][k] == longinf ? 0 : dist[j][k]);
    }
  }
  cout << ans << endk;
  return 0;
}
