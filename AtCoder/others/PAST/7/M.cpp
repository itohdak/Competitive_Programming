#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
  int n, c; cin >> n >> c;
  vector<int> A(n); rep(i, n) cin >> A[i];
  mcf_graph<ll, ll> G(2*n+2);
  rep(i, n) G.add_edge(i, n+i, 1, 0);
  rep(i, n) REP(j, i+1, n) G.add_edge(n+i, j, 1, abs(A[j]-A[i]));
  rep(i, n) G.add_edge(2*n, i, 1, c);
  rep(i, n) G.add_edge(n+i, 2*n+1, 1, 0);
  auto [cap, cost] = G.flow(2*n, 2*n+1, 3);
  // auto ret = G.slope(2*n, 2*n+1);
  // for(auto [cap, cost]: ret) {
  //   cout << cap << ' ' << cost << endk;
  // }
  // auto E = G.edges();
  // for(auto [from, to, cap, flow, cost]: E) {
  //   if(flow == 0) continue;
  //   cout << from << ' ' << to << ' ' << flow << endk;
  // }
  cout << cap << ' ' << cost << endk;
  return 0;
}
