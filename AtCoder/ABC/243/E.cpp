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

ll dist[300][300] = {0};
void warshall_floyd(int n) {
  rep(i, n) rep(j, n) rep(k, n) {
    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> A(m), B(m), C(m);
  rep(i, n) rep(j, n) if(i != j) dist[i][j] = longinf;
  rep(i, m) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--; B[i]--;
    dist[A[i]][B[i]] = C[i];
    dist[B[i]][A[i]] = C[i];
  }
  warshall_floyd(n);
  int cnt = 0;
  rep(i, m) {
    int a = A[i], b = B[i];
    bool ok = false;
    rep(j, n) {
      if(j == a || j == b) continue;
      if(dist[a][j] + dist[b][j] == dist[a][b]) ok = true;
    }
    if(ok) cnt++;
  }
  cout << cnt << endk;
  return 0;
}
