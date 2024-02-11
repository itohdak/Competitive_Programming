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
  vector<vector<vector<string>>> A(3, vector<vector<string>>(4, vector<string>(4, string(4, '.'))));
  rep(i, 3) rep(j, 4) cin >> A[i][0][j];
  rep(i, 3) {
    rep(j, 4) rep(k, 4) {
      A[i][1][j][k] = A[i][0][3-k][j];
      A[i][2][j][k] = A[i][0][3-j][3-k];
      A[i][3][j][k] = A[i][0][k][3-j];
    }
  }
  vector<string> B(4, string(4, '.'));
  auto dfs = [&](auto dfs, int cur) -> bool {
    if(cur == 3) {
      bool ok = true;
      rep(j, 4) {
	if(B[j] != string(4, '#')) ok = false;
      }
      return ok;
    }
    vector<string> Borig = B;
    rep(t, 4) {
      for(int j0=-4; j0<=4; j0++) {
	for(int k0=-4; k0<=4; k0++) {
	  bool ok = true;
	  B = Borig;
	  rep(j, 4) {
	    rep(k, 4) {
	      int x = j0+j, y = k0+k;
	      if(A[cur][t][j][k] == '#') {
		if(x < 0 || x >= 4 || y < 0 || y >= 4) {
		  ok = false;
		} else if(B[x][y] == '#') {
		  ok = false;
		} else {
		  B[x][y] = '#';
		}
	      }
	    }
	    if(!ok) continue;
	  }
	  if(ok) {
	    // cout << cur << ' ' << B << endk;
	    if(dfs(dfs, cur+1)) return true;
	  }
	}
      }
    }
    return false;
  };
  cout << (dfs(dfs, 0) ? "Yes" : "No") << endk;
  return 0;
}
