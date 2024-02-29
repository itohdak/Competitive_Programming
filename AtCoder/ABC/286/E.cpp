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
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  vector<vector<int>> dist(n, vector<int>(n, inf));
  vector<vector<ll>> V(n, vector<ll>(n));
  rep(i, n) {
    rep(j, n) {
      if(j == i) dist[i][j] = 0;
      else if(S[i][j] == 'Y') {
        dist[i][j] = 1;
        V[i][j] = A[j];
      }
    }
  }
  rep(i, n) rep(j, n) rep(k, n) {
    if(dist[j][k] > dist[j][i] + dist[i][k]) {
      dist[j][k] = dist[j][i] + dist[i][k];
      V[j][k] = V[j][i] + V[i][k];
    } else if(dist[j][k] == dist[j][i] + dist[i][k]) {
      if(j == i && i == k) continue;
      chmax(V[j][k], V[j][i] + V[i][k]);
    }
  }
  int q; cin >> q;
  rep(i, q) {
    int u, v; cin >> u >> v;
    u--; v--;
    if(dist[u][v] == inf) cout << "Impossible" << endk;
    else cout << dist[u][v] << ' ' << V[u][v]+A[u] << endk;
  }
  return 0;
}
