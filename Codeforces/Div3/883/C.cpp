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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, m, h; cin >> n >> m >> h;
  vector<vector<int>> T(n, vector<int>(m));
  vector<pair<int, ll>> point(n);
  rep(i, n) {
    rep(j, m) cin >> T[i][j];
    sort(all(T[i]));
    vector<ll> cum(m+1);
    rep(j, m) cum[j+1] = cum[j] + T[i][j];
    int cnt = upper_bound(all(cum), h) - begin(cum) - 1;
    ll pen = 0;
    rep(j, cnt+1) pen += cum[j];
    point[i] = {cnt, -pen};
  }
  int cnt = 1;
  REP(i, 1, n) {
    if(point[i] > point[0]) cnt++;
  }
  cout << cnt << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}