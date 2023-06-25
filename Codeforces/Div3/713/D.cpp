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
  int n; cin >> n;
  vector<ll> B(n+2); rep(i, n+2) cin >> B[i];
  multiset<ll> st; rep(i, n+2) st.insert(B[i]);
  ll sum = accumulate(all(B), 0LL);
  rep(i, n+2) {
    ll tmp = sum - B[i];
    if(tmp % 2 == 0) {
      st.erase(st.find(B[i]));
      if(st.count(tmp/2)) {
        st.erase(st.find(tmp/2));
        for(ll ele: st) cout << ele << ' ';
        cout << endk;
        return;
      }
      st.insert(B[i]);
    }
  }
  cout << -1 << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
