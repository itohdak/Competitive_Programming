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
  ll BIG = inf;
  int n; cin >> n;
  vector<int> A(n), B(n);
  vector<ll> C(n);
  rep(i, n) cin >> A[i] >> B[i] >> C[i];
  vector<vector<ll>> mx(150, vector<ll>(150));
  int m = 150;
  mcf_graph<ll, ll> G(2*m+2);
  int s = 2*m, t = 2*m+1;
  rep(i, n) {
    A[i]--;
    B[i]--;
    G.add_edge(A[i], m+B[i], 1, BIG-C[i]);
  }
  rep(i, m) {
    G.add_edge(s, i, 1, 0);
  }
  rep(i, m) {
    G.add_edge(m+i, t, 1, 0);
  }
  auto ret = G.slope(s, t);
  int cap_mx = ret.back().first;
  vector<ll> ans(cap_mx+1);
  int l = 0;
  REP(i, 1, cap_mx+1) {
    while(l < ret.size() && ret[l].first < i) l++;
    if(i == ret[l].first) {
      auto [x, y] = ret[l];
      ans[i] = BIG*x-y;
    } else {
      auto [x1, y1] = ret[l-1];
      auto [x2, y2] = ret[l];
      y1 = BIG*x1-y1;
      y2 = BIG*x2-y2;
      ans[i] = y1*(x2-i)+y2*(i-x1)/(x2-x1);
    }
  }
  cout << cap_mx << endk;
  REP(i, 1, cap_mx+1) cout << ans[i] << endk;
  return 0;
}
