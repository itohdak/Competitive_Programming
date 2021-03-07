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
  int n; ll t; cin >> n >> t;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  int n1 = n/2, n2 = n-n1;
  set<ll> st1, st2;
  rep(i, 1<<n1) {
    ll sum = 0;
    rep(j, n1) {
      if((i>>j)&1) {
        sum += A[j];
      }
    }
    st1.insert(sum);
  }
  rep(i, 1<<n2) {
    ll sum = 0;
    rep(j, n2) {
      if((i>>j)&1) {
        sum += A[n1+j];
      }
    }
    st2.insert(sum);
  }
  ll ans = 0;
  for(auto ele: st1) {
    auto itr = st2.upper_bound(t-ele);
    if(itr == st2.begin()) continue;
    itr--;
    chmax(ans, ele+*itr);
  }
  cout << ans << endk;
  return 0;
}
