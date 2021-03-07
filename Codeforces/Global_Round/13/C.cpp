#include <bits/stdc++.h>
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
  vector<ll> S(n); rep(i, n) cin >> S[i];
  ll ans = 0;
  set<ll> st;
  rep(i, n) st.insert(i);
  st.insert(longinf);
  rep(i, n) {
    if(S[i] > n) {
      ans += S[i]-n;
      S[i] = n;
    }
    while(S[i] > 1) {
      ll p = i;
      ans++;
      while(p < n) {
        ll ne = *st.lower_bound(p + S[p]);
        S[p] = max(1LL, S[p]-1);
        if(S[p] == 1) st.erase(p);
        p = ne;
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

