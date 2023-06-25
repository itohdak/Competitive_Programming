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
  int n, m; cin >> n >> m;
  vector<int> A(m), B(m);
  rep(i, m) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
  }
  vector<ll> C(n);
  rep(i, n) cin >> C[i];
  mf_graph<ll> G(2*n);
  rep(i, n) {
    G.add_edge(i, i+n, C[i]);
  }
  rep(i, m) {
    G.add_edge(A[i]+n, B[i], longinf);
    G.add_edge(B[i]+n, A[i], longinf);
  }
  auto ans = G.flow(n, n-1);
  auto ret = G.min_cut(n);
  cout << ans << endk;
  vector<int> V;
  REP(i, 1, n-1) if(ret[i] != ret[i+n]) V.push_back(i);
  cout << V.size() << endk;
  for(auto v: V) cout << v+1 << ' ';
  cout << endk;
  return 0;
}
