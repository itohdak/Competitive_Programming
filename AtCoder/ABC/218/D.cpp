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
  set<pair<int, int>> st;
  vector<pair<int, int>> P(n);
  rep(i, n) {
    int x, y; cin >> x >> y;
    P[i] = {x, y};
    st.insert(P[i]);
  }
  ll ans = 0;
  rep(i, n) REP(j, i+1, n) {
    auto [x1, y1] = P[i];
    auto [x2, y2] = P[j];
    if(x1 == x2 || y1 == y2) continue;
    if(!st.count({x1, y2})) continue;
    if(!st.count({x2, y1})) continue;
    ans++;
  }
  cout << ans/2 << endk;
  return 0;
}
