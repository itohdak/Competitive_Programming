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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, m; cin >> n >> m;
  string s; cin >> s;
  vector<vector<vector<int>>> cnt(3, vector<vector<int>>(3, vector<int>(n+1)));
  rep(i, 3) { // mod
    rep(j, 3) { // abc
      rep(k, n) {
        cnt[i][j][k+1] = cnt[i][j][k] + (i==k%3 && s[k]-'a'==j);
      }
    }
  }
  // cout << cnt << endk;
  rep(_, m) {
    int l, r; cin >> l >> r;
    l--;
    int ans = inf;
    rep(i, 3) {
      rep(j, 3) {
        if(i == j) continue;
        int k = 3-i-j;
        int tmp = 0;
        tmp += (r-l-1)/3+1 - (cnt[l%3][i][r]-cnt[l%3][i][l]);
        if(l+1 < r) tmp += (r-(l+1)-1)/3+1 - (cnt[(l+1)%3][j][r]-cnt[(l+1)%3][j][l]);
        if(l+2 < r) tmp += (r-(l+2)-1)/3+1 - (cnt[(l+2)%3][k][r]-cnt[(l+2)%3][k][l]);
        // cout << char('a'+i) << char('a'+j) << char('a'+k) << ' ' << tmp << endk;
        chmin(ans, tmp);
      }
    }
    cout << ans << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
