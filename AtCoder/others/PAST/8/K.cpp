#include <bits/stdc++.h>
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
  int p, q; cin >> p >> q;
  vector<string> S(p); rep(i, p) cin >> S[i];
  vector<ll> A(p), B(p), C(q), D(q);
  rep(i, p) cin >> A[i] >> B[i];
  rep(i, q) cin >> C[i] >> D[i];
  mcf_graph<int, ll> G(p+q+2);
  ll BIG = 2000000000;
  int s = p+q, t = p+q+1;
  rep(i, p) G.add_edge(s, i, 1, 0);
  rep(i, q) G.add_edge(p+i, t, 1, 0);
  rep(i, p) rep(j, q) {
    if(S[i][j]-'0' && A[i]-B[i]+C[j]-D[j] >= 0) {
      G.add_edge(i, p+j, 1, BIG-(A[i]-B[i]+C[j]-D[j]));
    }
  }
  auto result = G.slope(s, t);
  ll ans = 0;
  ll sum = accumulate(all(B), 0LL) + accumulate(all(D), 0LL);
  for(auto [flow, cost]: result) {
    chmax(ans, sum+BIG*flow-cost);
  }
  cout << ans << endk;
  // auto result = G.flow(s, t);
  // auto edges = G.edges();
  // int cnt = 0;
  // for(auto e: edges) {
  //   if(e.from == s || e.to == t || e.flow == 0) continue;
  //   cnt++;
  // }
  // ll ans = 0;
  // ans += accumulate(all(B), 0LL);
  // ans += accumulate(all(D), 0LL);
  // ans += cnt * BIG - result.second;
  // cout << ans << endk;
  return 0;
}
