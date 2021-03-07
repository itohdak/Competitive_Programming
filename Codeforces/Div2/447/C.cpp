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
  int m; cin >> m;
  vector<int> S(m);
  set<int> st;
  rep(i, m) {
    cin >> S[i];
    st.insert(S[i]);
  }
  vector<int> ans(2*m, S[0]);
  rep(i, m) ans[i*2] = S[i];
  // cout << ans << endk;
  rep(i, 2*m) {
    int g = ans[i];
    REP(j, i, 2*m) {
      g = __gcd(ans[j], g);
      // cout << i << ' ' << j << ' ' << g << endk;
      if(!st.count(g)) {
        cout << -1 << endk;
        return 0;
      }
    }
  }
  cout << ans.size() << endk;
  rep(i, 2*m) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
