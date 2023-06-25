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
  int n, m, k; cin >> n >> m >> k;
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  vector<string> T(n, string(m, '.'));
  rep(i, n) rep(j, m) {
    if(S[i][j] == '.') continue;
    int l = 0, r = 0;
    while(i-l >= 0 && j-l >= 0 && S[i-l][j-l] == '*') {
      l++;
    }
    while(i-r >= 0 && j+r < m && S[i-r][j+r] == '*') {
      r++;
    }
    l--; r--;
    int mn = min(l, r);
    if(mn < k) continue;
    rep(l, mn+1) T[i-l][j-l] = '*';
    rep(r, mn+1) T[i-r][j+r] = '*';
  }
  bool ok = true;
  rep(i, n) if(S[i] != T[i]) ok = false;
  cout << (ok ? "YES" : "NO") << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
