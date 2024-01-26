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
  int n; cin >> n;
  ll ans = 0;
  for(int mx=1; mx<=n*n; mx++) {
    rep(i, n) {
      if(mx%(i+1) || mx/(i+1)>n) {
	continue;
      }
      if(ans >= mx*(n-1)) continue;
      set<int> st;
      for(int j=1; j<=n; j++) {
	if(j != mx/(i+1)) st.insert(j);
      }
      bool ok = true;
      ll tmp = 0;
      rrep(j, n) {
	if(j == i) continue;
	auto itr = st.upper_bound(mx/(j+1));
	if(itr == st.begin()) {
	  ok = false;
	  break;
	}
	--itr;
	tmp += 1LL * (*itr) * (j+1);
	st.erase(itr);
      }
      if(ok) {
	chmax(ans, tmp);
      }
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
