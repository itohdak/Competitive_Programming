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
  int n; cin >> n;
  string t; cin >> t;
  int m = t.size();
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  vector<int> mx(n), mn(n);
  rep(i, n) {
    {
      int cur = 0;
      rep(j, S[i].size()) {
	if(cur >= m) break;
	if(S[i][j] == t[cur]) {
	  cur++;
	}
      }
      mx[i] = cur;
    }
    {
      int cur = m-1;
      rrep(j, S[i].size()) {
	if(cur < 0) break;
	if(S[i][j] == t[cur]) {
	  cur--;
	}
      }
      mn[i] = cur;
    }
  }
  vector<int> cnt(m+1);
  rep(i, n) cnt[mn[i]+1]++;
  vector<int> cum(m+2);
  rep(j, m+1) cum[j+1] = cum[j] + cnt[j];
  ll ans = 0;
  rep(i, n) {
    ans += cum[mx[i]+1];
  }
  cout << ans << endk;
  return 0;
}
