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

vector<pair<int, int>> conn; // result connections (edges in minimum spanning tree)
ll prim(int N, vector<vector<ll>>& cost) {
  vector<ll> mincost(N, inf);
  vector<bool> used(N, false);
  vector<int> from(N);
  mincost[0] = 0;

  ll res = 0;
  while(true) {
    int v = -1;
    rep(u, N) { if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u; }
    if(v == -1) break; // all vertices are covered
    used[v] = true;
    res += mincost[v];
    if(v != 0) { conn.push_back(make_pair(v, from[v])); }
    rep(u, N) {
      if(cost[v][u] < mincost[u]) {
        mincost[u] = cost[v][u];
        from[u] = v;
      }
    }
  }
  return res;
}

ll modpow(ll a, ll N, ll mod) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  ll BIG = inf;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<vector<ll>> C(n, vector<ll>(n, longinf));
  rep(i, n) rep(j, n) {
    if(i != j) {
      C[i][j] = inf - (modpow(A[i], A[j], m) + modpow(A[j], A[i], m)) % m;
    }
  }
  auto res = prim(n, C);
  cout << BIG*(n-1) - res << endk;
  return 0;
}
