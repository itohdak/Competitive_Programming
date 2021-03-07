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
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<vector<bool>> exists_left(n, vector<bool>(2)), exists_right(n, vector<bool>(2));
  rep(i, n) {
    rep(j, 2) {
      if(i && exists_left[i-1][j]) exists_left[i][j] = true;
      if(i+1 < n && (s[i]-'0' == j)) exists_left[i+1][j] = true;
    }
  }
  rrep(i, n) {
    rep(j, 2) {
      if(i+1 < n && exists_right[i+1][j]) exists_right[i][j] = true;
      if(i-1 >= 0 && (s[i]-'0' == j)) exists_right[i-1][j] = true;
    }
  }
  rep(_, q) {
    int l, r; cin >> l >> r;
    l--;
    // cout << s[l] << ' ' << s[r-1] << endk;
    cout << (exists_left[l][s[l]-'0'] || exists_right[r-1][s[r-1]-'0'] ? "YES" : "NO") << endk;
    // bool ok = false;
    // REP(i, 0, l) if(s[i] == s[l]) ok = true;
    // REP(i, r, n) if(s[i] == s[r-1]) ok = true;
    // cout << (ok ? "YES" : "NO") << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
