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
  int h, w, n; cin >> h >> w >> n;
  mf_graph<int> G(h+2*n+w+2);
  int s = h+2*n+w, t = h+2*n+w+1;
  rep(i, h) G.add_edge(s, i, 1);
  rep(i, n) G.add_edge(h+i, h+n+i, 1);
  rep(i, w) G.add_edge(h+2*n+i, t, 1);
  rep(i, n) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--; b--;
    REP(j, a, c) G.add_edge(j, h+i, 1);
    REP(k, b, d) G.add_edge(h+n+i, h+2*n+k, 1);
  }
  cout << G.flow(s, t) << endk;
  return 0;
}
