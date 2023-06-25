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
  int n; cin >> n;
  string s; cin >> s;
  vector<vector<int>> C(n+1, vector<int>(26));
  rep(i, n) rep(j, 26) C[i+1][j] = C[i][j] + (s[i]-'A' == j);
  int q; cin >> q;
  while(q--) {
    int l, r, k; cin >> l >> r >> k;
    l--;
    int mx = 0;
    rep(j, 26) chmax(mx, C[r][j]-C[l][j]);
    if(r-l < k) {
      cout << "No" << endk;
    } else if(mx > k) {
      cout << "No" << endk;
    } else {
      cout << "Yes" << endk;
      string ss;
      rep(j, 26) rep(k, C[r][j]-C[l][j]) ss += char('A'+j);
      string s2 = ss.substr(0, k);
      string s1 = ss.substr(k);
      reverse(all(s1));
      cout << s1 + s2 << endk;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
