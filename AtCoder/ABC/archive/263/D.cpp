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
  int n, l, r; cin >> n >> l >> r;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<ll> diff(n+1);
  rrep(i, n) {
    diff[i] = diff[i+1] + r - A[i];
  }
  multiset<ll> st;
  rep(i, n+1) st.insert(diff[i]);
  ll sum = accumulate(all(A), 0LL);
  ll mn = 0;
  ll tmp = 0;
  ll ans = longinf;
  rep(i, n+1) {
    chmin(ans, sum+mn+(st.empty()?0:*st.begin()));
    if(i < n) tmp += l - A[i];
    chmin(mn, tmp);
    st.erase(st.find(diff[i]));
  }
  cout << ans << endk;
  return 0;
}
