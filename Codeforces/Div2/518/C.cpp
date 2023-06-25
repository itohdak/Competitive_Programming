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
  int n, m; cin >> n >> m;
  vector<vector<pair<int, int>>> ans(n);
  rep(i, n) {
    ans[i].push_back({i, i*n+i});
  }
  rep(i, m) {
    int x, y; cin >> x >> y;
    x--; y--;
    ans[x].push_back({x, x*n+y});
    ans[x].push_back({x, y*n+x});
    ans[y].push_back({y, x*n+y});
    ans[y].push_back({y, y*n+x});
  }
  rep(i, n) {
    cout << ans[i].size() << endk;
    for(auto [x, y]: ans[i]) cout << x+1 << ' ' << y+1 << endk;
  }
  return 0;
}
