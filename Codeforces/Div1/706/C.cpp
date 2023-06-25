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
  vector<string> S(n); rep(i, n) cin >> S[i];
  rrep(i, n) {
    if(i == 0) continue;
    int l = 0, r = 0;
    while(l < m) {
      while(l < m && S[i][l] == '.') l++;
      r = l;
      while(r < m && S[i][r] == 'X') r++;
      bool ok = false;
      for(int j=l; j<r; j++) {
        if(S[i-1][j] == 'X') ok = true;
      }
      if(!ok) S[i-1][l] = 'X';
      l = r;
    }
  }
  rep(i, n) cout << S[i] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
