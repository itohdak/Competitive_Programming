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
  int n, k; cin >> n >> k;
  vector<int> D;
  while(n) {
    D.push_back(n%10);
    n /= 10;
  }
  reverse(all(D));
  vector<ll> pw(D.size());
  ll pw1 = 0;
  rep(i, D.size()) {
    if(i) pw[i] = pw[i-1] * 10;
    else  pw[i] = 1;
    pw1 = pw1 * 10 + 1;
  }
  set<int> st;
  ll ans = longinf;
  ll tmp = 0;
  // cout << D << endk;
  rep(i, D.size()) {
    if(D[i] < 9 && (st.count(D[i]+1) || st.size() < k)) {
      bool in = st.count(D[i]+1);
      st.insert(D[i]+1);
      ll tmp2 = tmp + (D[i]+1);
      tmp2 *= pw[D.size()-1-i];
      tmp2 += (pw1 / 10) * (st.size() < k ? 0 : *st.begin());
      chmin(ans, tmp2);
      if(!in) st.erase(D[i]+1);
    }
    st.insert(D[i]);
    if(st.size() > k) break;
    tmp += D[i];
    pw1 /= 10;
    tmp *= 10;
  }
  if(st.size() <= k) chmin(ans, tmp/10);
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
