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
  vector<string> S(8); rep(i, 8) cin >> S[i];
  rep(i, 8) {
    rep(j, 8) {
      if(S[i][j] != '.') {
	bool ok1 = false, ok2 = false;
	if(i+1 < 8 && S[i+1][j] != '.') ok1 = true;
	if(j+1 < 8 && S[i][j+1] != '.') ok2 = true;
	assert(!(ok1 && ok2));
	if(!ok1 && !ok2) cout << S[i][j] << endk;
	else if(ok1) {
	  string ans;
	  for(int ii=i; ii<8; ii++) {
	    if(S[ii][j] == '.') break;
	    ans += S[ii][j];
	  }
	  cout << ans << endk;
	}
	else {
	  string ans;
	  for(int jj=j; jj<8; jj++) {
	    if(S[i][jj] == '.') break;
	    ans += S[i][jj];
	  }
	  cout << ans << endk;
	}
	return;
      }
    }
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
