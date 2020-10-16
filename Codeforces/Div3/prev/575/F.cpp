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

vector<vector<ll>> dist;
void warshall_floyd(int n) {
  rep(i, n) rep(j, n) rep(k, n) {
    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
  }
}
void solve() {
  int n, m, k; cin >> n >> m >> k;
  vector<int> id(m), X(m), Y(m);
  vector<ll> W(m);
  rep(i, m) {
    cin >> X[i] >> Y[i] >> W[i];
    X[i]--; Y[i]--;
    id[i] = i;
  }
  sort(all(id), [&](int i, int j) {
    return W[i] < W[j];
  });
  vector<tuple<int, int, ll>> E;
  vector<int> V;
  rep(i, min(m, k)) {
    E.push_back({X[id[i]], Y[id[i]], W[id[i]]});
    V.push_back(X[id[i]]);
    V.push_back(Y[id[i]]);
  }
  sort(all(V));
  V.erase(unique(all(V)), end(V));
  dist.assign(V.size(), vector<ll>(V.size(), longinf));
  rep(i, V.size()) dist[i][i] = 0;
  for(auto [x, y, w]: E) {
    int xnew = lower_bound(all(V), x) - begin(V);
    int ynew = lower_bound(all(V), y) - begin(V);
    dist[xnew][ynew] = w;
    dist[ynew][xnew] = w;
  }
  warshall_floyd(V.size());
  vector<ll> D;
  rep(i, V.size()) REP(j, i+1, V.size()) {
    D.push_back(dist[i][j]);
  }
  sort(all(D));
  cout << D[k-1] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
