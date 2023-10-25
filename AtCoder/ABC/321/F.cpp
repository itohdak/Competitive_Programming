#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

using mint = modint998244353;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int q, k; cin >> q >> k;
  vector<mint> dp(k+1);
  dp[0] = 1;
  rep(i, q) {
    char c;
    int x;
    cin >> c >> x;
    if(c == '+') {
      vector<mint> next(k+1);
      copy(all(dp), begin(next));
      rep(j, k+1) {
	if(j+x <= k) {
	  next[j+x] += dp[j];
	} else {
	  break;
	}
      }
      dp = next;
    } else {
      vector<mint> prev(k+1);
      copy(begin(dp), begin(dp)+x, begin(prev));
      for(int j=x; j<=k; j++) {
	prev[j] = dp[j] - prev[j-x];
      }
      dp = prev;
    }
    // rep(j, k+1) cout << dp[j].val() << ' ';
    // cout << endk;
    cout << dp[k].val() << endk;
  }
  return 0;
}
